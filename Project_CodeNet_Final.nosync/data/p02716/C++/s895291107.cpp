#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


int n;
ll arr[200005];

map<ii,ll> memo;

const ll INF=1e18;

ll dp(int i,int j){
	if (i<0) return -INF;
	if (j==1) return arr[i];
	if (memo.count(ii(i,j))) return memo[ii(i,j)];
	if ((i%2==0 && i/2==j) || i/2==j-1){
		//cout<<i<<" "<<j<<endl;
		return memo[ii(i,j)]=max(dp(i-2,j-1),dp(i-3,j-1))+arr[i];
	}
	
	return -INF;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin>>n;
	
	for (int x=0;x<n;x++) cin>>arr[x];

	cout<<max(dp(n-3,n/2),max(dp(n-2,n/2),dp(n-1,n/2)));
}