﻿// CppHeui.cpp : 응용 프로그램의 진입점을 정의합니다.
//

#include "CppHeui.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "locale.h" 
#include <string>
#include <vector>
using namespace std;

//wchar to int
//int is method
auto strokeCount(wchar_t * s) ->int{
	switch (*s)
	{

	case L'ㄱ':
	case L'ㄴ':
	case L'ㅅ':
		return 2;

	case L'ㄷ':
	case L'ㅈ':
	case L'ㅋ':
		return 3;

	case L'ㅁ':
	case L'ㅂ':
	case L'ㅊ':
	case L'ㅌ':
	case L'ㅍ':
	case L'ㄲ':
	case L'ㄳ':
	case L'ㅆ':
		return 4;

	case L'ㄵ':
	case L'ㄹ':
	case L'ㄶ':
		return 5;

	case L'ㅄ':
		return 6;

	case L'ㄺ':
		return 7;

	case L'ㅀ':
		return 8;

	case L'ㄻ':
	case L'ㄼ':
		return 9;

	default:
		break;
	}
	return -1;
}

//wchar to int
auto stackIndices(wchar_t * s) -> int{
	switch (*s)
	{
	case L' ':
		return 0;
	case L'ㄱ':
		return 1;
	case L'ㄴ':
		return 2;
	case L'ㄷ':
		return 3;
	case L'ㄹ':
		return 4;
	case L'ㅁ':
		return 5;
	case L'ㅂ':
		return 6;
	case L'ㅅ':
		return 7;
	case L'ㅈ':
		return 8;
	case L'ㅊ':
		return 9;
	case L'ㅋ':
		return 10;
	case L'ㅌ':
		return 11;
	case L'ㅍ':
		return 12;
	case L'ㄲ':
		return 13;
	case L'ㄳ':
		return 14;
	case L'ㄵ':
		return 15;
	case L'ㄶ':
		return 16;
	case L'ㄺ':
		return 17;
	case L'ㄻ':
		return 18;
	case L'ㄼ':
		return 19;
	case L'ㄽ':
		return 20;
	case L'ㄾ':
		return 21;
	case L'ㄿ':
		return 22;
	case L'ㅄ':
		return 23;
	case L'ㅆ':
		return 24;
	default:
		break;
	}
	return -1;
}

//초성 
static const wchar_t wcHead[] = { L'ㄱ', L'ㄲ', L'ㄴ', L'ㄷ',
L'ㄸ', L'ㄹ', L'ㅁ', L'ㅂ',
L'ㅃ', L'ㅅ', L'ㅆ', L'ㅇ',
L'ㅈ', L'ㅉ', L'ㅊ', L'ㅋ',
L'ㅌ', L'ㅍ', L'ㅎ' };

//중성 
static const wchar_t wcMid[] = { L'ㅏ', L'ㅐ', L'ㅑ', L'ㅒ',
L'ㅓ', L'ㅔ', L'ㅕ', L'ㅖ',
L'ㅗ', L'ㅘ', L'ㅙ', L'ㅚ',
L'ㅛ', L'ㅜ', L'ㅝ', L'ㅞ',
L'ㅟ', L'ㅠ', L'ㅡ', L'ㅢ', L'ㅣ' };

//종성 
static const wchar_t wcTail[] = { L' ', L'ㄱ', L'ㄲ', L'ㄳ',
L'ㄴ', L'ㄵ', L'ㄶ', L'ㄷ',
L'ㄹ', L'ㄺ', L'ㄻ', L'ㄼ',
L'ㄽ', L'ㄾ', L'ㄿ', L'ㅀ',
L'ㅁ', L'ㅂ', L'ㅄ', L'ㅅ',
L'ㅆ', L'ㅇ', L'ㅈ', L'ㅊ',
L'ㅋ', L'ㅌ', L'ㅍ', L'ㅎ' };

/**
*
>use case<
BreakHan(str, buffer, sizeof buffer);
setlocale(LC_ALL, "Korean");
printf("%S", buffer);
*
*/
int BreakHan(wchar_t *str, wchar_t *buffer,unsigned int nSize)
{
	unsigned int pos = 0;
	while (*str != '\0')
	{
		if (*str < 256)
		{
			if (pos + 2 >= nSize - 1)
				break;

			buffer[pos] = *str;
			++pos;
		}
		else
		{
			if (pos + 4 >= nSize - 1)
				break;

			buffer[pos] = wcHead[(*str - 0xAC00) / (21 * 28)];
			buffer[pos + 1] = wcMid[(*str - 0xAC00) % (21 * 28) / 28];
			buffer[pos + 2] = wcTail[(*str - 0xAC00) % 28];
			pos += 3;
		}
		++str;
	}

	buffer[pos] = '\0';
	return pos;
}

struct Char
{
	wchar_t Lead;
	wchar_t Vowel;
	wchar_t Tail;
};

struct Storage
{
	int Type;
	vector<int> Memory;
};

struct Machine
{
	vector<Char> CodeSpace; // use like 2d array
	Storage* CurrentStorage;
	int xpos;
	int ypos;
	int dx;
	int dy;
	bool terminated;
	int run(string code) {
		vector<Char> codeSpace = initCodespace();
		this->CodeSpace = codeSpace;

		auto res = 0;
		auto Flag = false;

		while (Flag) {
			res; // will update
			Flag = this->terminated;
		}

		return res;
	};
	vector<Char> initCodespace() {
		return vector<Char>();
	};
};



int main()
{
	cout << "Start of Program" << endl;
	
	Machine machine{};
	machine.initCodespace();

	return 0;
}
