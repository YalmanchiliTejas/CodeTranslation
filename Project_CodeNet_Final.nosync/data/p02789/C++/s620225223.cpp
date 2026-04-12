#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++);

ll gcd(ll a,ll b){
  while(b!=0){
    a%=b;
    swap(a,b);
  }
  return a;
}

ll kaizyou(ll N){
  ll num=1;
  for(ll i=1;i<=N;i++){
  num*=i;
  }
  return num;
}

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};

int main(){
  int N,M;
  cin >> N >> M;
  if(N==M){
    cout << "Yes"  <<endl;
  }
  else{
    cout << "No" << endl;
  }
}
      
  
  
  