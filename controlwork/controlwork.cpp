#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	FILE* stream;
	char ch;
	setlocale(LC_ALL, "rus");
	char finame[25];
	printf("Введите имя файла: ");
	cin >> finame;
	fopen_s(&stream, finame, "r");
	if (stream == NULL) {
		printf("Не удается открыть файл\n");
		exit(1);
	}
	if ((ch = fgetc(stream) > 'А') && (ch = fgetc(stream) < 'Я') || (ch = fgetc(stream) > 'а') && (ch = fgetc(stream) > 'я')) {
		printf("Данные введены некорректно, введите текст файла латиницей.\n");
		exit(1);
	}
	while ((ch = fgetc(stream)) != EOF) {
		cout << ch << ' ';
	}
	fclose(stream);
	return 0;
}