 #include <bits/stdc++.h>
 #include <string> 
 #include <math.h>
 #include <bitset>
 #include <numeric>
 #include <stdio.h>
 #include <algorithm>

 using namespace std;

 int main(){
    long long N,i;
    long long A[220000];
    long long p_sum[220000];
    long long ans=0;
    long long tmp_mod=0;
    cin >> N;

    for (i=0; i<N; i++)
        cin >> A[i];

    p_sum[0]=A[0];
   
    for (i=1; i<N; i++)
        p_sum[i]=p_sum[i-1]+A[i];
   
    for (i=0; i<N-1; i++){
        tmp_mod=(p_sum[N-1]-p_sum[i])%1000000007;
        ans = ans + A[i]*tmp_mod;
        ans = ans%1000000007;
        }
    cout << ans << endl;

    return 0;
 }
 

