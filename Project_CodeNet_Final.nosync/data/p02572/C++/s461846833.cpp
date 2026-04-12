
// Problem: C - Sum of product of pairs
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ll long long
const int N = 2e5+5;
const int mod = 1e9+7;
#define ld long double
#define PI 3.14159265358979323846
const int INF = 10000000;
 
void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
}
 
//3. Structure or classes
//3. Ends here
 
//1. Data structures declaration here
//1. Ends here
 
//2. Extra Functions here
//2. Ends here
 
 
void solve();
int32_t main()
{
    flash();
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<"\n";
    }
    return 0;
}
 
 
 
void solve()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int sum[n]={0};
	sum[0]=a[0];
	
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+a[i];
		sum[i]%=mod;
	}
	
	int ans=0;
	for(int i=0;i<n-1;i++){
		ans = ans + (a[i] * (sum[n-1]-sum[i]))%mod;
		ans = (ans+mod)%mod;
	}
	
	cout<<ans<<"\n";
    return;
}
// how r u bro