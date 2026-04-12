#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define N 200001
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
 return ans.x;
}
int dp[1002][5][2];
int k;
string str;
int n;
int solve(int pos , int cnt , bool tight){
   if(pos == n && cnt == k)
   return 1;
   else if(pos == n && cnt != k)
   return 0;
 if(dp[pos][cnt][tight] != -1)
 return dp[pos][cnt][tight];
 ll ret = 0;
 ll en = tight?(str[pos]-'0'):9;
 for(int i = 0 ; i <= en ; i++){
  ll cntupd = cnt + (i > 0);
  if(cntupd <= k){
     ret += solve(pos + 1 , cntupd , (tight&(i==en)));
  }
 }
 return (dp[pos][cnt][tight] = ret);
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>str;
n = str.length();
cin>>k;
memset(dp , -1 , sizeof dp);
//~ for(int i = 0 ; i < 1002 ; i++){
 //~ for(int j = 0 ; j < 5 ; j++){
  //~ for(int k = 0 ; k < 2 ; k++){
   //~ cout<<dp[i][j][k]<<" ";
  //~ }
  //~ //cout<<endl;
 //~ }}
ll ans = solve(0 , 0 , true);
cout<<ans<<endl;
}
