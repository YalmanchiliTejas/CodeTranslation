#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//do {
//    print(v);
//  } while (std::next_permutation(v.begin(), v.end()));
ll atusa[51]={1};
ll paty[51]={1};

ll dp(ll n,ll x){
	if(n==0){
		if(x>0)return 1;
		else
		 return 0;
	}
	else if(x<=1+atusa[n-1])
		return dp(n-1,x-1);
	else
		return paty[n-1]+1+dp(n-1,x-2-atusa[n-1]);
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);

	ll N,X;
	cin>>N>>X;
	eFOR(i,1,N){
		atusa[i]=atusa[i-1]*2+3;
		paty[i]=paty[i-1]*2+1;
	}
	cout<<dp(N,X)<<endl;
	
	return 0;
}


















