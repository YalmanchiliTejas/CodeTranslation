#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#define INF (1<<29)
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;


int v,e;
vector<int> edge[100000];
string a;
set<char> able[100000];

int main(){
	cin>>v>>e;
	rep(i,v){
		rep(j,26)able[i].insert('a'+j);
	}
	rep(i,v){
		char c;
		cin>>c;
		a+=c;
	}
	rep(i,e){
		int s,t;
		cin>>s>>t;
		edge[s].push_back(t);
		edge[t].push_back(s);
	}
	rep(i,v){
		if(a[i]=='?')continue;
		rep(j,edge[i].size()){
			able[edge[i][j]].erase(a[i]);
		}
	}
	rep(i,v){
		if(a[i]!='?')continue;
		char c=*able[i].begin();
		a[i]=c;
		rep(j,edge[i].size()){
			able[edge[i][j]].erase(c);
		}
	}
	cout<<a<<endl;
	return 0;
}
