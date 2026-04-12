#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<numeric>
#include<algorithm>
#include<string>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#define int long long
const int inf=8938103643641919514ll;
const int mod=1000000007ll;
const int dd[]={0,-1,0,1,0};
using namespace std;
int pri[10001];
int ps;
struct A{
	vector<A*> e;
};
using pa=vector<A*>;
A p[8];
signed main(){
	int ans=0,m,n;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		p[u].e.push_back(&p[v]);
		p[v].e.push_back(&p[u]);
	}
	queue<pa> que;
	pa aa;
	aa.push_back(&p[0]);
	que.push(aa);
	while(!que.empty()){
		auto x=que.front();
		que.pop();
		if(x.size()==n){
			ans++;
			continue;
		}
		auto xx=*rbegin(x);
		for(auto y:xx->e){
			auto z=x;
			bool f=true;
			for(auto w:z)
				if(w==y)
					f=false;
			if(f){
				z.push_back(y);
				que.push(z);
			}
		}
	}
	cout<<ans<<endl;
}