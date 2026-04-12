#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

int countChar(char c,string s){
	if(s.find_first_of(c)==string::npos) return 0;
	return s.find_last_of(c)-s.find_first_of(c)+1;
}

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	// your code goes here
	int n=read();
	string s[n];
	REP(i,n){
		cin >> s[i];
		sort(s[i].begin(),s[i].end());
	}
	int count;
	int count0;
	string ans;
	REP(j,s[0].length()){
		count0 = countChar(s[0][j],s[0]);
		count = count0;
		FOR(i,1,n){
			count = min(count,countChar(s[0][j],s[i]));
		}
		REP(k,count) ans.push_back(s[0][j]);
		j += count0-1;
	}
	cout << ans;
}