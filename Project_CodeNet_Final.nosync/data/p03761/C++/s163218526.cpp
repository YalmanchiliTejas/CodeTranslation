#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define lld long double
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

lli data[60][26];

signed main(){

	lli n;
	cin>>n;

	REP(i,0,n){
		string s;
		cin>>s;
		REP(j,0,s.size()){
			data[i][s.at(j)-'a']++;
		}
	}

	lli minNum[26]={INF};
	REP(i,0,26)minNum[i]=INF;

	REP(i,0,n)REP(j,0,26){
		if(DEBUG)cout<<"i="<<i<<" j="<<j<<" data[i][j]="<<data[i][j]<<endl;
		minNum[j] = min(minNum[j],data[i][j]);
	}

	REP(i,0,26){
		if(DEBUG)cout<<minNum[i]<<endl;
		REP(j,0,minNum[i])cout<<(char)('a'+i);
	}
	cout<<endl;

	return 0;
}