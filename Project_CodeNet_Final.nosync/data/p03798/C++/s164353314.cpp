#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<string>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
//std::ios::sync_with_stdio(false);
using namespace std;
const int maxn = 1e5 + 5;
int ani[maxn];
char s[maxn];
int len;
int endd,begi;
bool execute() {
	int i = 1;
	while (i <= len - 1) {
		if (ani[i]) {
			if (s[i] == 'o')ani[i + 1] = ani[i - 1];
			else ani[i + 1] = !ani[i - 1];
		}
		else {
			if (s[i] == 'x')ani[i + 1] = ani[i - 1];
			else ani[i + 1] = !ani[i - 1];
		}
		i++;
	}
	if (ani[len - 1] == endd&&ani[len]==begi) return 1;
	else return 0;
};
void print() {
	for (int i = 0; i < len; i++) {
		if (ani[i])printf("S");
		else printf("W");
	}
}
int main() {
	cin >> len;
	scanf("%s", s);
	//1sheet,0wolf
	//case1 
	begi=ani[0] = 1;
	if (s[0] == 'o')
	{
		ani[1] = 1;  endd = 1; if (execute()) { print();return 0; } 
		ani[1] = 0;  endd = 0; if (execute()) { print();  return 0; }
	}
	else {
		ani[1] = 1;  endd = 0; if (execute()) { print();  return 0; }
		ani[1] = 0;  endd = 1; if (execute()) { print(); return 0; }
	}
	//case 2
	begi=ani[0] = 0;
	if (s[0] == 'x') {
		ani[1] = 1;  endd = 1; if (execute()) { print(); return 0; }
		ani[1] = 0;  endd = 0; if (execute()) { print(); return 0; }
	}
	else {
		ani[1] = 1;  endd = 0; if (execute()) { print();return 0; }
		ani[1] = 0;  endd = 1; if (execute()) { print();  return 0; }
	}
	cout << -1;
//system("pause");
return 0;
}
