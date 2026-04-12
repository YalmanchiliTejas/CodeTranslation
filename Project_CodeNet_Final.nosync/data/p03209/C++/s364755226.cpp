#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pLL;
typedef long long ll;
int MOD = 1000000007;

ll a[60];
ll p[60];

ll f(int N, ll X){
  if(N <= 0){
    if(X <= 0){
      return 0;
    }else{
      return 1;
    }
  }else if(X <= a[N-1] + 1){
    return f(N-1,X-1);
  }else{
    return p[N-1] + 1 + f(N-1,X-a[N-1]-2);
  }
}

int main(){
  int N;
  ll X;
  cin >> N >> X;
  
  a[0] = 1;
  p[0] = 1;
  for(int i=0; i<N; i++){
    a[i+1] = 2*a[i] + 3;
    p[i+1] = 2*p[i] + 1;
  }
  cout << f(N,X) << endl;
    
  return 0;
}