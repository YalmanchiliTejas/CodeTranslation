#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
#define ck(n,a,b) (a<=(n)&&(n)<b)
#define F first
#define S second
typedef long long ll;
using namespace std;

int main(){
	int n;
	cin>>n;
	string s[51];
	map<int,int> m[51];
	REP(i,0,n) {
		cin>>s[i];
		REP(j,0,(int)s[i].size()) m[i][s[i][j]-'a']++;
	}

	string ans="";
	REP(i,0,26){
		int tmp=100;
		char now='a'+i;
		REP(j,0,n) tmp=min(tmp,m[j][i]);
		REP(j,0,tmp){
			ans+=now;
		}
	}
	p(ans);
	return 0;
}
