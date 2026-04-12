#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
   ll n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n){
      cin >> a.at(i);
   }
   ll sum=0;
   rep(i,n){
      sum+=a.at(i);
   }
   sum%=MM;
   ll ans=sum*sum;
   rep(i,n){
      ll x=a.at(i)*a.at(i);
      x%=MM;
      ans-=x;
      if(ans<0)ans+=MM;
   }
   ll b=(MM+1)/2;
   ans%=MM;
   ans*=b;
   ans%=MM;
   cout << ans << endl;
} 