#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  ll N;
  ll s[1100];
  cin>>N;
  while(N){
  ll sum=0;
  for(ll i = 0; i < N; ++i){
      cin >> s[i];
  }
  sort(s,s+N);
  for(ll i = 1; i < N-1; ++i){
    sum+=s[i];
  }
  cout<<sum/(N-2)<<endl;
  cin>>N;
  }
}

    
  
  
  



