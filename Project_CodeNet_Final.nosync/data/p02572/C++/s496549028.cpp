#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
#define fix(n) cout << fixed << setprecision(n)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(long i=a; i<=b; i++)
#define REN(i, a, b) for(long i=b; i>=a; i--)
// Debugging 
#define line cout << endl
#define out(n) cout << n << " "
#define bug(n) cout << n << "\n"
#define print(arr, start, end) REP(i, start, end) out(arr[i]); line

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef map<int, int> mii;

///// General Purpose functions /////

/////////////////

void solve(){
	int n;
  	cin >> n;
  
  	ll A[n];
  	ll pre_sum[n];
  	cin >> A[0];
    pre_sum[0] = A[0];
  	
  	REP(i,1,n-1)
    {
      cin >> A[i];
      pre_sum[i] = (pre_sum[i-1]%MOD + A[i]%MOD)%MOD; 
    }
  
  	ll ans = 0;
    ll psum = 0;
  	REP(i,0,n-2)
    {
      psum = (pre_sum[n-1] - pre_sum[i] + MOD)%MOD;
      psum = ((A[i]%MOD)*(psum%MOD))%MOD;
      ans =  (ans%MOD + psum%MOD)%MOD;
    }
  	
  	bug(ans);
}

void prep(){

}

int main()
{
	//code
	io;
	int t = 1;
	//cin >> t;
	prep();
	fix(12);
	while(t--){
	    solve();
	}
	
	return 0;
}