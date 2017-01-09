#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {
	char name[100];
	char surname[100];
	int age;
} user;

int main(int argc, char *argv[]) {
	int choose;
	FILE *usersFile;
	
	while(choose != 6) {
		system("CLS");
		printf("Menu:\n");
		printf("1.\tAdd user\n");
		printf("2.\tShow users\n");
		printf("3.\tLookup users by name\n");
		printf("4.\tLookup users by surname\n");
		printf("5.\tLookup users by age\n");
		printf("6.\tExit\n\n");
		printf("Choose: ");
		scanf("%d", &choose);
		
		switch(choose) {
			case 1:
				usersFile = fopen("test.txt", "a");
				addUser(usersFile);
				fclose(usersFile);
				break;
			case 2:
				usersFile = fopen("test.txt", "r");
				showUsers(usersFile);
				fclose(usersFile);
				break;
			case 3:
				usersFile = fopen("test.txt", "r");
				lookupByName(usersFile);
				fclose(usersFile);
				break;
			case 4:
				usersFile = fopen("test.txt", "r");
				// lookupBySurname(usersFile);
				fclose(usersFile);
				break;
			case 5:
				usersFile = fopen("test.txt", "r");
				// lookupByAge(usersFile);
				fclose(usersFile);
				break;
			default:
				break;
		}
	}
	
	return 0;
}

void addUser(FILE *usersFile) {
	char name[100];
	char surname[100];
	int age;
	user rec;
	
	system("CLS");
	if(usersFile == NULL) {
		printf("[err] Error while opening the usersFile.");
		exit(1);
	}
	printf("[i] Insert your name: ");
	scanf("%s", &name);
	printf("[i] Insert your surname: ");
	scanf("%s", &surname);
	printf("[i] Insert your age: ");
	scanf("%d", &age);
	
	strcpy(rec.name, name);
	strcpy(rec.surname, surname);
	rec.age = age;
	
	fprintf(usersFile, "%s %s %d\n", rec.name, rec.surname, rec.age);
	fclose(usersFile);
	
	printf("[ok] Error while opening the usersFile.\n");
}

void showUsers(FILE *usersFile) {
	user rec;
	
	system("CLS");
	if(usersFile == NULL) {
		printf("[err] Error while opening the usersFile.");
		exit(1);
	}
	printf("Name       | Surname    | Age \n");
	while(!feof(usersFile)) {
		fscanf(usersFile, "%s%s%d\n", &rec.name, &rec.surname, &rec.age);
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	fclose(usersFile);
	system("PAUSE");
}

void lookupByName(FILE *usersFile) {
	char name[100];
	user rec;
	
	system("CLS");
	printf("[i] Insert name to search for: ");
	scanf("%s", &name);
	
	system("CLS");
	if(usersFile == NULL) {
		printf("[err] Error while opening the usersFile.");
		exit(1);
	}
	printf("Name       | Surname    | Age \n");
	while(!feof(usersFile)) {
		fscanf(usersFile, "%s%s%d\n", &rec.name, &rec.surname, &rec.age);
		if(strcmp(rec.name, name) == 0)
			printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	fclose(usersFile);
	system("PAUSE");
}
