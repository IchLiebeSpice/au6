// au6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

char UI() {
	printf("%s\n", "Choose from the following");
	printf("%s\n", "1. Create file");
	printf("%s\n", "2. Delete file");
	printf("%s\n", "3. View file");
	printf("%s\n", "Any key to exit");
	printf("%s", "Enter your choice: ");
	fflush(stdin);
	return getchar();
}

int create()
{
	char file_name[1000];
	printf("%s\n", "Locate your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", &file_name);
	FILE* file_ptr = fopen(file_name, "w");
	fclose(file_ptr);
	printf("File was successful created. Closing the program\n");   
	return 0;
}

int rmv() {
	char file_name[1000];
	printf("%s\n", "Location your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", &file_name);
	if (remove(file_name) == 0)
		printf("Deleted successfully\n");
	else
		printf("Unable to delete the file\n");

	return 0;
}

int view()
{
	FILE *f;
	char file_name[1000];
	char str[999];
	printf("%s\n", "Locate your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", &file_name);
	f = fopen(file_name, "r+");

	if (!f) {
		printf("Error while opening file: %s\n", file_name);
		return -1;
	}

	fgets(str, 255, (FILE*)f);
	printf("%s\n", str);
	fclose(f);
}

int main()
{
	FILE *f;
	int(*pf)(int, int) = NULL;
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
		default:
			pf = NULL;
		}
	} while (pf);
	return 0;
}
