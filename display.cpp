#include <stdio.h>
#include <Windows.h>

void enterToContinue() {
    printf("Press enter to continue.\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}


void menuDisplay() {
	system("cls");
	printf("Welcome to my bad text editor!\n");
	printf("\nMenu:\n");
	printf("1. Text Editor\n");
	printf("2. Information and Credits (IMPORTANT TO READ IF NEVER OPEN)\n");
	printf("3. Exit\n");
	
	printf("Pick an option: \n");
	printf(">> ");
}

void creditsDisplay() {
	system("cls");
	printf("Keybinds used in this program:\n");
	printf("1. F1 Key -> Used for saving text into a .txt file.\n");
	printf("2. Enter Key -> Used to make newline in editor.\n");
	printf("3. ESC Key -> Used to exit the editor.\n");
	printf("3. DEL Key -> This is purely just a visual feature, and has no effect on the resulting saved file!\n\n");
	
	printf("The max characters you can have within the editor is 5k characters.\nThere should be a way to make it consistently add up with malloc, but I'm lazy.\n\n");
	printf("Made by Me\n");
	printf("11//2//2024\n");
	enterToContinue();
}


