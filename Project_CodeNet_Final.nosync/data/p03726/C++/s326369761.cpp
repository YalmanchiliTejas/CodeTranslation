#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
set<int> gr[114514];
bool sumi[114514];
queue<int> le;
int main()
{
	memset(sumi,false,sizeof(sumi));
	int n,a,b;
	cin>>n;
	rep(i,n-1){
		cin>>a>>b;
		gr[a].insert(b);gr[b].insert(a);
	}
	rep(i,n+1){
		if(gr[i].size()==1) le.push(i);
	}
	while(le.size()){
		int x=le.front();le.pop();
		if(sumi[x]) continue;
		//cout<<x<<endl;
		if(gr[x].size()==0){
			cout<<"First"<<endl;return 0;
		}
		int y=(*gr[x].begin());
		sumi[x]=sumi[y]=true;
		vector<int> v=vector<int>(All(gr[y]));
		rep(i,v.size()){
			gr[v[i]].erase(y);
			if(!sumi[v[i]] && gr[v[i]].size()<2) le.push(v[i]);
		}
	}
	cout<<"Second"<<endl;
}
