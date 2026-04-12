#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin>>N;
  long  mod=1e9+7;
  vector<long> a(N);
  vector<long> s(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
    }
    s[0]=a[0];
    for(int i=1;i<N;i++){
      s[i]=s[i-1]+a[i];
      s[i]%=mod;

    }
  long ans=0;

for(int i=0;i<N;i++){
  long tmp = s[N-1]-s[i];
  if(tmp<0) tmp+=mod;
  ans+=a[i]*(tmp);
  ans%=mod;

}

cout<<ans<<endl;
}
