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
	
	while(choose != 13) {
		system("CLS");
		printf("Menu:\n");
		printf(" 1.\tAdd user\n");
		printf(" 2.\tShow users\n");
		printf(" 3.\tLookup users by name\n");
		printf(" 4.\tLookup users by surname\n");
		printf(" 5.\tLookup users by age\n");
		printf(" 6.\tSort by name\n");
		printf(" 7.\tSort by surname\n");
		printf(" 8.\tSort by age\n");
		printf(" 9.\tSort by name and surname\n");
		printf("10.\tSort by name, then age\n");
		printf("11.\tSort by surname, then age\n");
		printf("12.\tSort by name and surname, then age\n");
		printf("13.\tExit\n\n");
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
				lookupBySurname(usersFile);
				fclose(usersFile);
				break;
			case 5:
				usersFile = fopen("test.txt", "r");
				lookupByAge(usersFile);
				fclose(usersFile);
				break;
			case 6:
				usersFile = fopen("test.txt", "r");
				sortByName(usersFile);
				fclose(usersFile);
				break;
			case 7:
				usersFile = fopen("test.txt", "r");
				sortBySurname(usersFile);
				fclose(usersFile);
				break;
			case 8:
				usersFile = fopen("test.txt", "r");
			    sortByAge(usersFile);
				fclose(usersFile);
				break;
			case 9:
				usersFile = fopen("test.txt", "r");
				sortByNameAndSurname(usersFile);
				fclose(usersFile);
				break;
			case 10:
				usersFile = fopen("test.txt", "r");
				sortByNameAndAge(usersFile);
				fclose(usersFile);
				break;
			case 11:
				usersFile = fopen("test.txt", "r");
				sortBySurnameAndAge(usersFile);
				fclose(usersFile);
				break;
			case 12:
				usersFile = fopen("test.txt", "r");
				sortByNameSurnameAndAge(usersFile);
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

void lookupBySurname(FILE *usersFile) {
	char surname[100];
	user rec;
	
	system("CLS");
	printf("[i] Insert surname to search for: ");
	scanf("%s", &surname);
	
	system("CLS");
	if(usersFile == NULL) {
		printf("[err] Error while opening the usersFile.");
		exit(1);
	}
	printf("Name       | Surname    | Age \n");
	while(!feof(usersFile)) {
		fscanf(usersFile, "%s%s%d\n", &rec.name, &rec.surname, &rec.age);
		if(strcmp(rec.surname, surname) == 0)
			printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	fclose(usersFile);
	system("PAUSE");
}

void lookupByAge(FILE *usersFile) {
	int age;
	user rec;
	
	system("CLS");
	printf("[i] Insert age to search for: ");
	scanf("%d", &age);
	
	system("CLS");
	if(usersFile == NULL) {
		printf("[err] Error while opening the usersFile.");
		exit(1);
	}
	printf("Name       | Surname    | Age \n");
	while(!feof(usersFile)) {
		fscanf(usersFile, "%s%s%d\n", &rec.name, &rec.surname, &rec.age);
		if(rec.age == age)
			printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	fclose(usersFile);
	system("PAUSE");
}

void sortByName(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(strcmp(users[j].name, users[i].name) < 0) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

void sortBySurname(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(strcmp(users[j].surname, users[i].surname) < 0) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

void sortByAge(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(users[j].age < users[i].age) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

void sortByNameAndSurname(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(strcmp(users[j].name, users[i].name) < 0 && strcmp(users[j].surname, users[i].surname) < 0) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

void sortByNameAndAge(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(strcmp(users[j].name, users[i].name) < 0 && users[j].age < users[i].age) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(users[j].age < users[i].age) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

void sortBySurnameAndAge(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(strcmp(users[j].surname, users[i].surname) < 0) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(users[j].age < users[i].age) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

void sortByNameSurnameAndAge(FILE *usersFile) {
	int numOfElements, i, j, min;
	user rec;
	user *users;
	
	system("CLS");
	
	numOfElements = getLinesQuantity(usersFile);
	users = malloc (numOfElements * sizeof(user));
	getUsersArray(usersFile, numOfElements, users);
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(strcmp(users[j].name, users[i].name) < 0 && strcmp(users[j].surname, users[i].surname) < 0) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	for(i = 0; i < numOfElements; i++) {
		min = i;
		for(j = i + 1; j < numOfElements; j++) {
			if(users[j].age < users[i].age) {
				min = j;
			}
		}
		
		rec = users[i];
		users[i] = users[min];
		users[min] = rec;
	}
	
	printf("Name       | Surname    | Age \n");
	for(i = 0; i < numOfElements; i++) {
		rec = users[i];
		printf("%10s | %10s | %10d\n", rec.name, rec.surname, rec.age);
	}
	
	system("PAUSE");
}

int getLinesQuantity(FILE *usersFile) {
	char a[100];
	char b[100];
	int c;
	int lines = 0;
	
	fclose(usersFile);
	usersFile = fopen("test.txt", "r");
	
	while(!feof(usersFile)) {
		fscanf(usersFile, "%s%s%d\n", &a, &b, &c);
		lines++;
	}
	
	fclose(usersFile);
	usersFile = fopen("test.txt", "r");
	
	return lines;
}

void getUsersArray(FILE *usersFile, int elements, user *output) {
	char name[100];
	char surname[100];
	int age;
	
	int ind = 0;
	
	fclose(usersFile);
	usersFile = fopen("test.txt", "r");
	
	while(!feof(usersFile)) {
		fscanf(usersFile, "%s%s%d\n", &name, &surname, &age);
		strcpy(output[ind].name, name);
		strcpy(output[ind].surname, surname);
		output[ind].age = age;
		ind++;
	}
	
	fclose(usersFile);
	usersFile = fopen("test.txt", "r");
}
