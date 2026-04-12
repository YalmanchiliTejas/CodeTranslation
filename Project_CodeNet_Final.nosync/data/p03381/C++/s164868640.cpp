#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int>v(N),a(N);

for(int i=0;i<N;i++)cin>>v[i];
for(int i=0;i<N;i++)a[i]=v[i];

sort(v.begin(),v.end());
for(int i=0;i<N;i++){
  if(a[i]<=v[N/2-1])cout<<v[N/2]<<endl;
  else cout<<v[N/2-1]<<endl;
}
}
