#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

ll modfact(ll x){
  if(x==1) return 1;
  else return (x*modfact(x-1))%mod;
}

int main(){
  int N;
  cin>>N;
  int a;
  deque<int> dq;
  for(int i=0;i<N;i++){
    cin>>a;
    if(i%2) dq.push_back(a);
    else dq.push_front(a);
  }

  if(N%2==0){
    reverse(dq.begin(),dq.end());
  }
  for(auto i:dq){
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}