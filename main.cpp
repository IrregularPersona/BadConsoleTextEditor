#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>

#define ERR (-1)
#define MAX_CHAR 5005

int main() {

	char *text = NULL;
	char ch;
	int index = 0;
	bool editingActive = true;
	int choice;

	do {
		menuDisplay();
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				system("cls");
				text = (char *)malloc(sizeof(char) * MAX_CHAR);

				if (text == NULL) {
					printf("MEM ALLOC FAILED\n");
					return 0;
				}

				while (editingActive) {
					ch = _getche();

					if (ch == ERR) {
						printf("Failed to read character!\n");
						continue;
					} else if (ch ==  27) {
						break;
					} else if (ch == '\r') {
						text[index++] = '\n';
						putchar('\n');
					} else if (ch ==  0) {
						ch = _getch();

						if (ch ==  59) {
							editingActive = false;
						}

					} else {
						if (index >= MAX_CHAR - 1) { 
							printf("Text length limit reached.\n");
							break;
						}
						text[index++] = ch;
					}
				}

				if (!editingActive) {
					char fileName[100];
					printf("\nEnter file name to save: ");
					scanf("%99s", fileName);

					char fileWithExtension[104];
					snprintf(fileWithExtension, sizeof(fileWithExtension), "%s.txt", fileName);

					FILE *file = fopen(fileWithExtension, "w");

					if (file == NULL) {
						printf("Error opening file for writing.\n");
					} else {
						text[index] = '\0';
						fprintf(file, "%s", text);

						fclose(file);
						printf("File saved as %s.\n", fileWithExtension);
					}
				}
				break;

			case 2:
				creditsDisplay();
				break;

			case 3:
				system("cls");
				printf("Thanks for using the program!\n");
				printf("We hope you come back and use this again!");
				break;

			default:
				printf("Please enter a valid option!\n");
				break;
		}
	} while (choice != 3);

	free(text);

	return 0;
}
