 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 10e8+7;
 // const ll INF = 1000000000000000000LL;
 
 int main(){
	 int n;
	 cin >> n;
	 vector<ll> a(n);
	 rep(i,n) cin >> a[i];
	 vector<int> sum(n);
	 rep(i,n-1){
		 sum[i+1] = sum[i]+a[i];
		 sum[i+1] %=MOD;
	 }
	 ll ans=0;
	 for(int i=n-1;i>0;i--){
		 ans += sum[i]*a[i];
		 ans %=MOD;
	 }
	 cout << ans << endl;
 }