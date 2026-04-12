#include <bits/stdc++.h>
using namespace std;

long long f(string N, int i, int j){
  int M = N.size();
  if(j<0) return 0;
  if(j==0) return 1;
  if(M-i-1<j) return 0;
  
  long long ret = 1;
  for(int k=0;k<j;k++) ret *= (M-i-1)-k;
  for(int k=1;k<=j;k++) ret /= k;
  for(int k=0;k<j;k++) ret *= 9;
  return ret;
}

int main(){
  string N;
  int K;
  cin >> N >> K;
  
  int j = K;
  long long ans = f(N,0,j);
  j--;
  ans += f(N,0,j) * ((N[0]-'0')-1);
  for(int i=1;i<N.size();i++){
    if(N[i]=='0') continue;
    else{
      ans += f(N,i,j);
      j--;
      ans += f(N,i,j) * ((N[i]-'0')-1);
    }
  }
  int cnt=0;
  for(int i=0;i<N.size();i++){
    if(N[i]!='0') cnt++;
  }
  if(cnt==K) ans++;
  
  cout << ans << endl;
  return 0;
}
