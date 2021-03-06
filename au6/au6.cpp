// au6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

char UI();
void create();
void rmv();
int view();


int main()
{
	int is_working = true;
	do {
		switch (UI()) {
		case '1':
			create();
			break;
		case '2':
			rmv();
			break;
		case '3':
			view();
			break;
		default:
			is_working = false;
			printf("The End\n");
		}
		fflush(stdin);
	} while (is_working);
	return 0;
}

char UI() {
	printf("%s\n", "Choose from the following");
	printf("%s\n", "1. Create file");
	printf("%s\n", "2. Delete file");
	printf("%s\n", "3. View file");
	printf("%s\n", "Any key to exit");
	printf("%s", "Enter your choice: ");
	fflush(stdin);
	return tolower(getchar());
}

void create()
{
	FILE *f;
	char file_name[1000];
	printf("%s\n", "Locate your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", file_name);
	f = fopen(file_name, "w");
	fclose(f);
	printf("File was successful created. Closing the program\n");
	getchar();
}

void rmv() {
	char file_name[1000];
	int rem;
	printf("%s\n", "Location your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", file_name);
	rem = remove(file_name);
	if (rem == 0) {
		printf("Deleted successfully\n");
	}
	else {
		printf("Unable to delete the file\n");
	}
	getchar();
}

int view()
{
	FILE *f;
	char file_name[1000];
	char str[999];
	printf("%s\n", "Locate your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", file_name);
	f = fopen(file_name, "r+");

	if (!f) {
		printf("Error while opening file: %s\n", file_name);
		return -1;
	}
	while (!feof(f)) {
		fgets(str, 255, (FILE*)f);
		printf("%s", str);
	}
	fclose(f);
	getchar();
}
