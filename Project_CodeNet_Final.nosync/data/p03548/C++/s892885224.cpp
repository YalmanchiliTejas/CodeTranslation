#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<list>
#include<cstdint>
#include<vector>
#include<map>
#define rep(i,rept)	for(ll i = 0; i<rept;i++)
typedef long long ll;
using namespace std;

long long int a = 0, b = 0, c = 1, x = 0, y = 0, z = 0, maxy = -1, mini = 9999, counter = 0,startp=0,endp=0,checker=0;
std::vector<unsigned long long int> vec{}, vecsec{};
int iremono[100001];
std::vector<long long int>kinds{}, ans{}, kaku{};
char moji,moji2;
bool okada = false,okada2=false;
std::string output, output2, input, one, two;
char cutcount[201];
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

	cin >> a >> b >> c;
	cout << (a - c) / (b + c) << endl;
}

	
	



