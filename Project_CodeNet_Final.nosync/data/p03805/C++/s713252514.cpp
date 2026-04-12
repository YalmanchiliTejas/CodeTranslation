#include "bits/stdc++.h"

using namespace std;

const char en = '\n';
using  ll =          long long;
using ull = unsigned long long;

#define REP(i  ,n) for(int i=0;i<n;i++)
#define FOR(i,s,g) for(int i=s;i<g;i++)

const ll INFL = 810000001919114514;
const int INF =         1919114514;



bool graph[8][8];
int  N,M;
bool checked[8];
int checkedcount=0;
int result=0;

int search(int i){
	checked[i]=true;
	checkedcount++;
	//cout<<i<<' '<<checkedcount<<en;
	if(checkedcount==N){
		result++;
	} else{
		REP(r,N){
			if(graph[i][r]&&!checked[r]) search(r);
		}
	}
	checked[i]=false;
	checkedcount--;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);cin.tie();
	
	cin>>N>>M;

	REP(i,8) fill_n(graph[i],8,false);
	         fill_n(checked ,8,false);

	int a,b;

	REP(i,M){
		cin>>a>>b;
		a--;
		b--;
		graph[a][b]=true;
		graph[b][a]=true;
	}

	search(0);

	cout<<result<<en;

	return 0;
}