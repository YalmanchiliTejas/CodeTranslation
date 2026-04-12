#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=998244353 ;

vector<int> v[202020];
void dfs(int x, int p, vector<int>& d){
	for(auto to:v[x]){
		if(to==p)continue;
		d[to] = d[x] + 1;
		dfs(to,x,d);
	}
}


int main(){
    int n;
    cin>>n;
    rep(i,n-1){
		int x,y;
		cin>>x>>y;
		--x;--y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> d1(n),d2(n),d3(n);
	dfs(0,-1,d1);
	int l = max_element(d1.begin(),d1.end())-d1.begin();
	dfs(l,-1,d2);
	int r = max_element(d2.begin(),d2.end())-d2.begin();
	dfs(r, -1, d3);
    int mi = 1;
    rep(i,n){
        if(d2[i]+d3[i]==d2[r])continue;
        if(d2[i]==d3[i]&&d3[i]==d2[r])continue;
        mi = max(max(d2[i],d3[i]),mi);
    }
    REP(i,1,n+1){
        if(i<=2)cout<<1;
        else if(i<=mi)cout<<0;
        else cout<<1;
    }
    cout<<endl;
    return 0;
}

