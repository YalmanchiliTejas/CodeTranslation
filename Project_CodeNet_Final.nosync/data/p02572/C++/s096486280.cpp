#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll; 
const int mod=1e9+7;
int n;
int main (){
   cin>>n;
   vector<int> a(n);
   int s=0;
  for(int i=0;i<n;i++){
   cin>>a[i];
    s=((ll)s+a[i])%mod;
  }
  s=(ll)s*s%mod;
  for(int ai:a)s=(s-ai*(ll)ai)%mod;
  s=(ll)s*((mod+1)/2)%mod;
  cout<<((ll)s+mod)%mod<<endl;
  return 0;
}

