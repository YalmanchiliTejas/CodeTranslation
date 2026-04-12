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
int n;
int arr[N];
map<pi , int> dp;
const int MIN = -1e18;
int fun(int idx , int k){
   //if(idx >= n && k > 0)return MIN;
   if(k ==0 && idx >= n)return 0;
   if(idx >= n)return MIN;
   //cout<<"idx :"<<idx<<" "<<"k : "<<k<<" ";
    if((n-idx+1)/2 < k)return MIN;
   if(dp.count({idx , k}) > 0)return dp[{idx , k}];
   //cout<<"idx :"<<idx<<" "<<"k : "<<k<<" "<<" n-idx :"<<n-idx<<" <= "<<2*k+1<<endl;
   //if(v[idx])return dp[idx];
  // v[idx] = true;
   int sum = 0;
   if(k > 0){
     sum = arr[idx]+fun(idx+2 , k-1);
 }
   int op2 = fun(idx+1 , k);
   return dp[{idx , k}] = max(sum , op2);
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n;
for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
}
//memset(v , false , sizeof(v));
cout<<fun(0 , n/2)<<endl;
}
