#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int main() {
	char s, ok[5] = {'a', 'i', 'u', 'e', 'o'};
	cin >> s;
	bool flag = false;
	REP(i, 5){
		if(s == ok[i]){
			flag = true;
		}
	}

	if(flag){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}
	return 0;
}