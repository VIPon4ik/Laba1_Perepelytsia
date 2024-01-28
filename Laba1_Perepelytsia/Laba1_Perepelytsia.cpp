#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int length = 4;
	string password = "";

	cout << "Введіть довжину пароля (4-32): ";
	cin >> length;

	if (length > 32) {
		length = 32;
	}
	else if (length < 4) {
		length = 4;
	}


	for (int j = 0; j < 10; j++) {

		for (int i = 0; i < length; i++) {
			int randomNum = rand() % (126 - 33 + 1) + 33;
			password += char(randomNum);
		}

		cout << password << endl;
		password = "";
	}
}