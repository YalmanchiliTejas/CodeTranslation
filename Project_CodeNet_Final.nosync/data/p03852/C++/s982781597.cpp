#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
#include <cmath>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
	char a;
	cin >> a;
	if(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')
		cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}
