#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<functional>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X <<":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e14;
typedef std::pair<int,int> P;
struct edge{ int to,cost; };
#define VMAX 100000
//bool cmp(P a,P b){ return a.second < b.second;}

ll N,M,X,ans=0;
ll Lay[52],Py[52];

ll DP(ll n,ll x){
	if(n==0){
		if(x<=0) return 0;
		else return 1;
	}else if(x<=Lay[n-1]+1){
		return DP(n-1,x-1);
	}else{
		return Py[n-1]+1+DP(n-1,x-2-Lay[n-1]);
	}

}

int main(){
	std::ios_base::sync_with_stdio(false);
	cin>>N>>X;
	Lay[0]=Py[0]=1;
	REP(i,N){
		Lay[i+1]=2*Lay[i]+3;
		Py [i+1]=2*Py [i]+1;
		DEB(Lay[i+1])DEB(Py[i+1])END
	}
	ans=DP(N,X);
	cout<<ans<<endl;
	return 0;
}