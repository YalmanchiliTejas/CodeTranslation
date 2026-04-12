#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
typedef long long ll;
int main() {
	char a;
	cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')
		cout << "vowel" << endl;
	else cout << "consonant" << endl;
}