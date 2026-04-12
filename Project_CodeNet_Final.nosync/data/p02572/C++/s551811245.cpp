#include<iostream>
using namespace std;

int main()
{
 int N; cin >> N;
 long int A[N];
 long int accum[N+1];
 accum[0] = 0;
 long int mod = 1e9+7;
 for(int i=0;i<N;i++){
     long int A_i; cin >> A_i;
     A[i] = A_i;
     accum[i+1] = accum[i] + A_i;
 }
 long int ans = 0;
 for(int i=0;i<N;i++){
     ans+=A[i]*((accum[N]-accum[i+1])%mod);
     ans%=mod;
 }
 cout << ans << endl;
 return 0;
}