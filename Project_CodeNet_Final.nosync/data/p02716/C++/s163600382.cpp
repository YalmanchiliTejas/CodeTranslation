#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = std::pair<int,int>;

const ll N = 2e5 + 5;
ll n,a[N],sum[N],f[N];

int main(){
   cin >> n;
   cin >> a[1] >> a[2];
   sum[1] = a[1];
   sum[2] = a[2];
   
   for(int i=3;i<=n;i++){
      cin >> a[i];
      sum[i] = sum[i-2] + a[i]; 
   }

   for(int i=2;i<=N;i++){
      if(i&1){
         f[i] = max(f[i-2] + a[i], f[i-1]);
      }else{
         f[i] = max(f[i-2] + a[i], sum[i-1]);
      } 
   }

   cout << f[n] << endl;
   return 0;  
}