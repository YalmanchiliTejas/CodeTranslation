#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

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

ll mod=1e9+7;

int main(){
  string S;
  cin >> S;
  bool ans=false;
  rep(i,S.size()-1){
    if(S.at(i)!=S.at(i+1)){
      ans=true;
    }
  }
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
      
  
  
  