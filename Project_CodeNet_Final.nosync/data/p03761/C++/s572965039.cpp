#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <climits>
#include <vector>
using namespace std;

#define ll long long int

const int MOD = 1000000007;

int main() {

	int N;
	string S[100];
	int countmin[26];
	int count[26];
	bool check[26];

	for (int i = 0; i < 26; i++) {

		countmin[i] = INT_MAX;
		check[i] = false;

	}

	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> S[i];

	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < 26; j++) {

			count[j] = 0;

		}

		for (int j = 0; j < S[i].size(); j++) {

			if (S[i][j] == 'a')count[0]++;
			if (S[i][j] == 'b')count[1]++;
			if (S[i][j] == 'c')count[2]++;
			if (S[i][j] == 'd')count[3]++;
			if (S[i][j] == 'e')count[4]++;
			if (S[i][j] == 'f')count[5]++;
			if (S[i][j] == 'g')count[6]++;
			if (S[i][j] == 'h')count[7]++;
			if (S[i][j] == 'i')count[8]++;
			if (S[i][j] == 'j')count[9]++;
			if (S[i][j] == 'k')count[10]++;
			if (S[i][j] == 'l')count[11]++;
			if (S[i][j] == 'm')count[12]++;
			if (S[i][j] == 'n')count[13]++;
			if (S[i][j] == 'o')count[14]++;
			if (S[i][j] == 'p')count[15]++;
			if (S[i][j] == 'q')count[16]++;
			if (S[i][j] == 'r')count[17]++;
			if (S[i][j] == 's')count[18]++;
			if (S[i][j] == 't')count[19]++;
			if (S[i][j] == 'u')count[20]++;
			if (S[i][j] == 'v')count[21]++;
			if (S[i][j] == 'w')count[22]++;
			if (S[i][j] == 'x')count[23]++;
			if (S[i][j] == 'y')count[24]++;
			if (S[i][j] == 'z')count[25]++;

		}

		for (int i = 0; i < 26; i++) {

			if (countmin[i] >= count[i]) {
			
				countmin[i] = count[i];
				check[i] = true;

			}
		}

	}

	for (int i = 0; i < 26; i++) {

		if (count[i] > 0) {

			for (int j = 0; j < countmin[i]; j++) {

				if (i == 0)cout << "a";
				if (i == 1)cout << "b";
				if (i == 2)cout << "c";
				if (i == 3)cout << "d";
				if (i == 4)cout << "e";
				if (i == 5)cout << "f";
				if (i == 6)cout << "g";
				if (i == 7)cout << "h";
				if (i == 8)cout << "i";
				if (i == 9)cout << "j";
				if (i == 10)cout << "k";
				if (i == 11)cout << "l";
				if (i == 12)cout << "m";
				if (i == 13)cout << "n";
				if (i == 14)cout << "o";
				if (i == 15)cout << "p";
				if (i == 16)cout << "q";
				if (i == 17)cout << "r";
				if (i == 18)cout << "s";
				if (i == 19)cout << "t";
				if (i == 20)cout << "u";
				if (i == 21)cout << "v";
				if (i == 22)cout << "w";
				if (i == 23)cout << "x";
				if (i == 24)cout << "y";
				if (i == 25)cout << "z";

			}

		}

	}

	cout << endl;

	return 0;
}