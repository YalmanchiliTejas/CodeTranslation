#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)

typedef long long ll;

int hand(char c){
	string right = "yuiophjklnm";
	int n = right.length();
	REP(i,n){
		if (c == right[i])
			return 1;
	}
	return 0;
}

int main(void){
	string s;
	while (cin >> s && s[0] != '#'){
		int ans = 0;
		int ho = hand(s[0]) , h;
		FOR(i,1,s.length()-1){
			h = hand(s[i]);
			if (h!=ho)
				ans++;
			ho = h;
		}
		cout << ans << endl;
	}

	return 0;
}