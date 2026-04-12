#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

// Most important thing in CP - Have Fun :)

ll binpow(ll a,ll p){
    ll res = 1 ;
    while (p>0){
        if (p & 1)res = (res*a)%hell;
        a = (a*a)%hell;
        p = p>>1;
    }
    return res;
}

void solve(){
	//write here
    ll n;
    cin>>n;
    vector<ll>arr(n);
    rep(i,0,n)cin>>arr[i];
    ll arr_sum = 0;
    rep(i,0,n)arr_sum = (arr_sum + arr[i])%hell;
    ll arr_sq_sum = (arr_sum * arr_sum)%hell;
    ll single_sq_sum = 0;
    rep(i,0,n)single_sq_sum=(single_sq_sum + arr[i]*arr[i])%hell;
    ll val = ((arr_sq_sum - single_sq_sum + hell)%hell * binpow(2,hell-2))%hell;
    cout<<val<<endl;
	return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	
		solve();
	return 0;
}