#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll MOD=1000000007;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   ll n;
   cin>>n;

   vector<int> a(26,0);
      string s;
      cin>>s;

      rep(j,s.size()){
         a[s[j]-'a']++;
      }

      rep(i,n-1){
         string c;
         cin>>c;
         vector<int> b(26,0);
         rep(j,c.size()){
            b[c[j]-'a']++;
         }

         rep(j,26){
            a[j]=min(a[j],b[j]);
         }
      }

      string ans="";

      rep(i,26){
         rep(j,a[i]){
         ans+=(char)('a'+i);
         }
      }   
      cout<<ans;
   return 0;
}
