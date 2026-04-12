#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=1; i<(int)(n); i++)
int main(){
long N, X, M, l, r, ans=0; cin >> N >> X >> M; 
long S[3*M]={}, L[3*M]={}, A[3*M]={};
A[0]=X; REP(i, 3*M){ A[i]=(A[i-1]*A[i-1])%M; }
S[0]=X; REP(i, 3*M){ S[i]=S[i-1]+A[i]; }
L[0]=-1; REP(i, 3*M){ L[i]=-1; }
L[X]=0;
REP(i, 3*M){ 
  if(L[A[i]]!=-1){ l=L[A[i]]; r=i; break; }
  else{ L[A[i]]=i; }
}
if(N<=2*M){ cout << S[N-1] << "\n"; return 0; }
long w=r-l, p=S[r]-S[l], W=N-l-1;
ans=S[l]; ans+=p*(W/w); ans+=(S[l+W%w]-S[l]);
cout << ans << "\n";
}
