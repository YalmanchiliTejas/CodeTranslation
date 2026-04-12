#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define rep(i,n) for(ll i=0;i<n;i++)

ll zetai(ll a,ll b){
  if(a>b) return a-b;
  else return b-a;
}

int main(){
  int x; cin>>x;
  if(x>=30) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  
  return 0;
}
