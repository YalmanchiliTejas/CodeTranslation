#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#ifndef FAST_IO
 #define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);
#endif

#define FILE_IO freopen("input.txt","r",stdin)
#define int long long
#define f first
#define s second
#define endl '\n'
#define all(c) c.begin(),c.end()
#define bp __builtin_popcount
#define debug(x) cerr << #x << " = " << x << endl;

const int MOD = 1e9 + 7;
const int INF = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>void print(T t){for(auto &it : t)cout<<it<<" ";}
inline int powerexp(int a, int b, int m = MOD){ int res = 1;while(b){if(b&1)res = res * a % m;a = a * a % m,b >>= 1;}return res % m;}
inline int modinv(int a){ return powerexp(a,MOD-2,MOD);}
inline int lcm(int a, int b){ int g = __gcd(a,b);return a/g*b;}
inline int add(int x, int y){ x += y; if (x >= MOD) x -=  MOD; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % MOD;}
inline int sub(int x, int y){ x -= y; if (x<0) x += MOD; return x ;}

//-------------------< start here >-------------------------// 

void print_vect(vector<int> v){
  for(int i = 0; i < (int)v.size(); i++){
	  if (i == (int)v.size() -1 ) cout << v[i] ;
	  else cout << " " << v[i]  ; 
	 }	
  cout << endl;
}

void solve(){
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 0; i < n; i++){
	  v.push_back(i);  
	}	
  for(int i = 0 ; i < (1 << n); i++){
	  vector<int> ret;
	  for(int j = 0; j < n; j++){
		  if (i & (1 << j)){
			  ret.push_back(v[j]);  
			}  
		}
      cout << i << ":" ;
      for(auto it : ret) cout <<  " " << it;
      cout << endl; 
	}
}

//-----------------------------
//comment from here for TOPCODER 
int32_t main(){
   IOS;
   solve();
   //find();
   #ifdef LOCAL_DEFINE
   cerr << "time elapsed " << (double)clock()/CLOCKS_PER_SEC << endl;
   #endif
}

