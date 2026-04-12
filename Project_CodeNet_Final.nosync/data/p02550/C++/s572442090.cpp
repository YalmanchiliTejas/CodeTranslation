#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define N 1000005
#define ll long long
#define int ll 
#define pi pair<int , int>
#define pip pair<pair ,int>
#define mp make_pair 
#define f first
#define s second
#define mod 998244353
ll Mod(ll x, ll y, int p) 
{ll res = 1; x = x % p;
while (y > 0) 
{if(y & 1) res = (res*x) % p; 
y = y>>1;x = (x*x) % p; 
}return res; 
}
int* getlps(string pattern){
 int len = pattern.length();
 int * lps = new int[len];
 lps[0] = 0;
 int i = 1 , j = 0;
 while(i < len){
  if(pattern[i] == pattern[j]){
	  lps[i] = j+1;
   i++;
   j++;
  }
  else{
		if(j != 0){
		 j = lps[j-1];
		}
		else{
		 lps[i] = 0;
		 i++;
		}
  }
 }
 return lps;
}
class Triplet{
 public:
 int x ;
 int y ;
 int gcd;
};
Triplet extendedEuclid(int a , int b){
 if(b == 0){Triplet ans; ans.gcd = a;ans.x = 1;ans.y = 0;return ans;}
 Triplet smallAns = extendedEuclid(b , a%b);
 Triplet ans;
 ans.gcd = smallAns.gcd;
 ans.x = smallAns.y;
 ans.y = smallAns.x - (a/b)*smallAns.y;
 return ans;
}
int mmInverse(int a , int m){
 Triplet ans = extendedEuclid(a , m);
 return (ans.x+m)%m;
}
int fact[N];
void calfac(int n ){
fact[0] = 1;
for(int i = 1 ; i <= n+2; i++){
 fact[i] = (((fact[i-1]%mod)*(i%mod))%mod + mod)%mod;
}
 }
int calc(int n , int r){
 if(r > n)return 0;
 if(r == n)return 1;
 int ans = 1;
 ans = ((ans%mod)*(fact[n])%mod + mod)%mod;
 ans = ((ans%mod)*(mmInverse(fact[n-r] , mod)%mod) + mod)%mod;
 ans = ((ans%mod)*(mmInverse(fact[r] , mod)%mod) + mod)%mod;
 return (ans+mod)%mod;
}
int dp[N+10];
void sieve(){
	  for(int i = 1 ; i <= N ;i++){
	  		dp[i] = i;
	  }
	  for(int i = 2 ; i <= N ;i++){
	  	  if(dp[i] == i){
	  	  	 for(int j = 2*i ; j <= N ;j+=i){
		  	  	 	  dp[j] = min(dp[j] , i);
	  	  	 }
	  	  }
	  }
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
int x , m;
cin>>n>>x>>m;
if(x == 0){
	cout<<"0"<<endl;
	return 0;
}
ll ans = 0;
ans+=x;
set<int> st;
st.insert(x);
int prev = x%m;
int cnt = 1;
int arr[100005];
memset(arr , -1 , sizeof(arr));
int i = 0;
int repeat = -1;
arr[i++] = x;
while(true){
   int z =  (((prev%m)*(prev%m)) + m)%m;
   if(st.find(z) != st.end()){
   	repeat = z;
   	arr[i++] = z;
   	break;
   }
   st.insert(z);
   prev = z;
   ans += z;
   arr[i++] = z;
   cnt++;
}
int stt = 0;
for(int i = 0 ; i < cnt ; i++){
	  if(arr[i] == repeat){
	  	      stt = i;
	  	     break;
	  }
}
int sum2 = 0;
for(int i = stt ; i < cnt ; i++){
	     sum2 += arr[i];
}
//cout<<"sum2: "<<sum2<<endl;
int times = (n-stt)/(cnt-stt);
for(int i = cnt-1 ; i >= stt ; i--){
	 ans -= arr[i];
     
}
//cout<<ans<<endl;
ans += times*sum2;
n -= stt;
int l = n - times*(cnt-stt);
int yy = 0;
for(int i = stt ;  yy < l ; i++ , yy++){
      	ans += arr[i];
}
cout<<ans<<endl;

}
