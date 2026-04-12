#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define BE(c) c.begin(),c.end()
#define PB push_back
#define F first
#define S second
#define BEB(s) s
using namespace std;
int main(){
	vector<int> grade;
	int g[31];
	int n,a,r[101],l[101];
	char com;
	while(cin>>n>>com>>a,n){
		grade.PB(a);
		r[n]=a;
	}
	sort(grade.begin(),grade.end());
	grade.erase(unique(grade.begin(),grade.end()),grade.end());
	int k=0;
	for(int i=grade.size()-1;i>=0;i--){
		k++;g[grade[i]]=k;
	}
	while(cin>>n){
		cout<<g[r[n]]<<endl;
	}
	return 0;
}