#include <bits/stdc++.h>
#define REP(i, a, b) for (long long i = a; i <= b; ++i)
#define ll long long
using namespace std;

ll a, b;
string s;

inline void work(){
	cin >> s;
	REP(i, 0, s.size() - 1){
		if (s[i] == 'A') a++;
		else b++;
	}
	if (a && b) puts("Yes");
	else puts("No");
}

int main(){
	work();
	return 0;
}