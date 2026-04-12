#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

unsigned long long int a = 0, b = 0, c =1, d = 0, e = 0, n = 0,x=0,y=0,z=0, maxy = 0, mini = 9999, counter = 0, sur = 0,kuso=0,kuso2=0,ans=0;
std::vector<unsigned long long int> vec{}, vecsec{};
unsigned long long int iremono[101][101];
std::vector<std::string>str{};
std::vector<std::string>str2{};
bool okada = false;
int arraykun[2300] = {}, nyan[1001] = {}, koji[50][50];
std::string output, output2, input,nyahhoi;
char kakunou[101][101] = {};
int kakunou2[50][50] = {};
int ctoi(const char c) {
	if ('0' <= c && c <= '9') return (c - '0');
	return -1;
}
unsigned long long int LCM(unsigned long long int a, unsigned long long int b) {
	unsigned long long int i, j;
	i = a; j = b;
	while (true) {
	
		c = i % j;
		i = j;
		if (c != 0) {
		
			j = c;

		}
		else {
			break;
		}
	}
	return j * (a / j) * (b / j);
}
int main()
{
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> kakunou[i][j];
		}
	}

	for (int j = 0; j < b; j++) {
		okada = false;
		for (int i = 0;i < a - 1; i++) {

			if (kakunou[i][j] == '.' &&kakunou[i+1][j] == '.') {

			}
			else {
				okada = true;
			}
			if (okada == false && i == a - 2) {
				for (int k = 0; k < a; k++)
					iremono[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		okada = false;
		for (int j = 0; j < b-1; j++) {
		
			if (kakunou[i][j] =='.' &&kakunou[i][j + 1]=='.') {
			}
			else {
				okada = true;
			}
			if (okada==false&&j == b - 2) {
				for (int k = 0; k < b;k++) {
					iremono[i][k] = 2;
				}
			}
		}
	}
	okada = false;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (iremono[i][j] ==2) {
				okada = true;
			}
			if (iremono[i][j] == 0) {
				cout << kakunou[i][j];
			}
		}
		if (!okada) {
			cout << endl;
		}
		else {
			okada = false;
		}
	}


}




