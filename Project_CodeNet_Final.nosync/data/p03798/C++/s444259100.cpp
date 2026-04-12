#include "bits/stdc++.h"
using namespace std;

using  ll =          long long;
using ull = unsigned long long;
const char en = '\n';
const ll INFL = 810000001919114514;
const int INF =         1919114514;

#define REP(i  ,n) for(int i=0;i<n;i++)
#define FOR(i,s,g) for(int i=s;i<g;i++)


char in[100000],b[4][100000];


char rev(char c){
	if(c=='S')
	return 'W';
	return 'S';
}
int main(){
	ios::sync_with_stdio(false);cin.tie();


	const char S='S',W='W';
	int n;
	cin>>n;

	REP(i,n){
		cin>>in[i];
	}

	b[0][0]=S;b[0][1]=S;
	b[1][0]=S;b[1][1]=W;
	b[2][0]=W;b[2][1]=S;
	b[3][0]=W;b[3][1]=W;

	FOR(i,1,n-1){
		REP(a,4){
			b[a][i+1]=((in[i]=='o')^(b[a][i]==W))?b[a][i-1]:rev(b[a][i-1]);
		}
	}

	/*
	REP(i,4){
		REP(j,n){
			cout<<b[i][j];
		}
		cout<<en;
	}
	*/
	REP(i,4){
		char c1=((in[n-1]=='o')^(b[i][n-1]==W))?b[i][n-2]:rev(b[i][n-2]);
		char c2=((in[0  ]=='o')^(b[i][0  ]==W))?b[i][n-1]:rev(b[i][n-1]);
		if(b[i][0]==c1&&b[i][1]==c2){
			REP(j,n){
				cout<<b[i][j];
			}
			cout<<en;
			return 0;
		}
	}
	cout<<-1<<en;


	return 0;
}
