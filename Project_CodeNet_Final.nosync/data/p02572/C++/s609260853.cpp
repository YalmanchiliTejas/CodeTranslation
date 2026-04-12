#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define M 1000000007

int main(){
   int n;
   cin>>n;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   vector<ll> sa(n);
   sa[n-1]=a[n-1];
   for(int i=n-2; i>=0; i--) sa[i]=(sa[i+1]+a[i])%M;

   ll cnt=0;
   rep(i, n-1){
      cnt=(cnt+a[i]*sa[i+1])%M;
   }

   cout<<cnt<<endl;
   return 0;
}
