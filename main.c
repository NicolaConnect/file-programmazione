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
	FILE *out;
	user rec;
	
	printf("[i] Insert your name: ");
	scanf("%s", &name);
	printf("[i] Insert your surname: ");
	scanf("%s", &surname);
	printf("[i] Insert your age: ");
	scanf("%d", &age);
	
	strcpy(rec.name, name);
	strcpy(rec.surname, surname);
	rec.age = age;
	
	out = fopen("test.txt", "w");
	if(out == NULL) {
		exit(1);
	}
	fprintf(out, "%s %s %d\n", rec.name, rec.surname, rec.age);
	fclose(out);
	
	return 0;
}
