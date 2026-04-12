#include <bits/stdc++.h>
using namespace std;
long long beki(long long n){
  long long a=1;
  for(int i=0;i<n;i++) a*=2;
  return a;
}
long long pati(long long n,long long x){
  long long c=beki(n+1)-2;
  if(n==0) return 1;
  else if(x==1) return 0;
  else if(x<=c) return pati(n-1,x-1);
  else if(x==c+1) return beki(n);
  else if(x<=2*c) return beki(n)+pati(n-1,x-c-1);
  else return 2*beki(n)-1;
}
int main() {
  long long n,x;
  cin>>n>>x;
  cout<<pati(n,x)<<endl;
}
