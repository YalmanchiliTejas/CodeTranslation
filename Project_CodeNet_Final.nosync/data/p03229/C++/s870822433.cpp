#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n; cin >> n;
	vi a(n); rep(i,n) cin >> a[i];
	SORT(a);
	ll ans = 0;
	ll sum = 0;
	int mid;
	if(n%2==0){
		mid = n/2;
		rep(i,n){
			if(i<mid-1) sum -= 2*a[i];
			else if(i==mid-1) sum -= a[i];
			else if(i==mid) sum += a[i];
			else sum += 2*a[i];
		}
		ans = sum;
	}else{
		mid = n/2;
		rep(i,n){
			if(i<mid-1) sum -= 2*a[i];
			else if(i==mid-1) sum -= a[i];
			else if(i==mid) sum -= a[i];
			else sum += 2*a[i];
		}
		ans = max(ans,sum);
		sum = 0;
		mid = (n+1)/2;
		rep(i,n){
			if(i<mid-1) sum -= 2*a[i];
			else if(i==mid-1) sum += a[i];
			else if(i==mid) sum += a[i];
			else sum += 2*a[i];
		}	
		ans = max(ans,sum);			
	}
	cout << ans << endl;	
}
