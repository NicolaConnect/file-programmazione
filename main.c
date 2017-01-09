#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {
	char name[100];
	char surname[100];
	int age;
} user;

int main(int argc, char *argv[]) {
	char name[100];
	char surname[100];
	int age;
	int choose;
	FILE *out;
	user rec;
	
	while(choose != 3) {
		system("CLS");
		printf("Menu:\n");
		printf("1.\tAdd user\n");
		printf("3.\tExit\n\n");
		printf("Choose: ");
		scanf("%d", &choose);
		
		switch(choose) {
			case 1:
				system("CLS");
				out = fopen("test.txt", "a");
				if(out == NULL) {
					printf("[err] Error while opening the file.");
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
				
				fprintf(out, "%s %s %d\n", rec.name, rec.surname, rec.age);
				fclose(out);
				
				printf("[ok] User added correctly.\n");
				system("PAUSE");
				break;
			default:
				break;
		}
	}
	
	return 0;
}
