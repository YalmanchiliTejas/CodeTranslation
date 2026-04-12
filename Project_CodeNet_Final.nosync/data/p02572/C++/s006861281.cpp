#include <bits/stdc++.h>
using namespace std;
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 1000000001

int main(){
	fast;
	int test=1;
	//cin >> test;
	while(test--){
	    int n;
	    cin >> n;
	    ll arr[n];
	    for(int i=0 ; i<n ; i++){
	        cin >> arr[i];
	    }
	    ll sum[n];
	    sum[n-1]=arr[n-1];
	    for(int i=(n-2) ; i>=0 ; i--){
	        sum[i]=sum[i+1]+arr[i];
	        sum[i]%=mod;
	    }
	    ll ans=0;
	    for(int i=0 ; i<(n-1) ; i++){
	        ans+=(arr[i]*(sum[i+1]));
	        ans%=mod;
	    }
	    cout << ans << endl;
	}
	return 0;
}