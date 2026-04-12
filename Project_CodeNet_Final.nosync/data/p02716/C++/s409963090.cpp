#include <bits/stdc++.h>
using namespace std;
const int Max=200000;
long A[Max]={}, f[Max]={}, seen[Max]={}, E[Max]={0};
long F(int n){
long M=0;
if(n==2){ M=max(A[0], A[1]); return M; }
if(n==3){ M=max(F(2), A[2]); return M; }
if(seen[n]){ return f[n]; }
seen[n]=1; 
if(n%2){ return f[n]=max(F(n-1), F(n-2)+A[n-1]); }
else{ return f[n]=max(E[n-2], F(n-2)+A[n-1]); }
}

int main(){
int N, i; cin >> N;
for(i=0; i<N; i++){ cin >> A[i]; }
E[0]=A[0];
for(i=2; i<N; i+=2){ E[i]=E[i-2]+A[i]; }  
cout << F(N) << "\n";
}