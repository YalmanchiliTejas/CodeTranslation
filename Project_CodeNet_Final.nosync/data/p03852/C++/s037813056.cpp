#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	// your code goes here
	char c;
	scanf("%c",&c);
	
	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') cout << "vowel";
	else cout << "consonant";
}