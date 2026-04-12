#include <bits/stdc++.h>
using namespace std;
long cas(string S, long k){
long i, s=S[0]-'0', l=S.size(), m=0; string T="";
if(l<k){ return 0; }
for(i=1; i<l; i++){ if(S[i]!='0'){ T=S.substr(i); break; } }
if(k==1){ return 9*(l-1)+s; }
else{
  if(k==3){ m=(s-1)*(l-1)*(l-2)*9*9/2+9*9*3*(l-1)*(l-2)*(l-3)/2; }
  else{ m=(s-1)*(l-1)*9+9*9*(l-1)*(l-2)/2; }
  return m+cas(T, k-1); }
}
int main(){
string N; long K; cin >> N >> K;
cout << cas(N, K) << "\n";
}