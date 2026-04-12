#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
template<class Type> void join(const Type &a){for(auto elem:a)cout<<elem<<' ';cout<<endl;}

int n,m;
bool path[8][8];
int ans=0;

void dfs(vi v,int num){
	vi tmp=v;
	tmp.push_back(num);
	sort(ALL(tmp));
	if(tmp.size()==n){
		ans++;
		return;
	}
	REP(i,n){
		if(path[num][i]){
			if(!binary_search(ALL(tmp),i)){
				dfs(tmp,i);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	
	REP(i,8)REP(j,8) path[i][j]=false;
	REP(i,m){
		int a,b;
		cin>>a>>b;
		path[a-1][b-1]=path[b-1][a-1]=true;
	}
	
	vi v;
	dfs(v,0);
	
	cout<<ans<<endl;
	return 0;
}