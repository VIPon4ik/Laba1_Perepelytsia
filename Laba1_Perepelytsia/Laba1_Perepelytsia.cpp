#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

// Функція, яка повертає рандомну літерау, базуючись на вибраних налаштуваннях
char getRandomChar(bool withDigits, bool withUpperChars, bool withSymbols) {
	int rangeSelector = rand() % 4;

	switch (rangeSelector) {
	case 0:
		if (withDigits) {
			return char(rand() % 10 + 48);
		}
	case 1:
		if (withUpperChars) {
			return char(rand() % 26 + 65);
		}
	case 2:
		if (withSymbols) {
			return char(rand() % 15 + 33);
		}
	default:
		return char(rand() % 26 + 97);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int length;
	bool withDigits = false, withUpperChars = false, withSymbols = false;
	string password = "", digitsSetting, upperCharsSetting, symbolsSetting;

	cout << "Введіть довжину пароля (4-32): ";
	cin >> length;

	// Валідація довжини, якщо вказано менше або більше за можливе, то присвоюється відповідно або максимальне допустиме значення, або мінімальне
	if (length > 32) {
		length = 32;
	}
	else if (length < 4) {
		length = 4;
	}

	// Додаткові налаштування паролю
	cout << "Чи буде містити цифри (yes/no): ";
	cin >> digitsSetting;
	cout << "Чи буде містити заглавні букви (yes/no): ";
	cin >> upperCharsSetting;
	cout << "Чи буде містити символи (yes/no): ";
	cin >> symbolsSetting;

	if (digitsSetting == "yes") {
		withDigits = true;
	}

	if (upperCharsSetting == "yes") {
		withUpperChars = true;
	}

	if (symbolsSetting == "yes") {
		withSymbols = true;
	}
	
	// Генерація 10 паролів та вивід їх в консоль. Якщо треба більше або менше - можна замінити параметр j в оголошенні цикла for
	for (int j = 0; j < 10; j++) {

		for (int i = 0; i < length; i++) {
			password += getRandomChar(withDigits, withUpperChars, withSymbols);
			
		}

		cout << password << endl;
		password = "";
	}
}
