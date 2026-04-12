#include<bits/stdc++.h>
using namespace std;

constexpr auto mod = static_cast<ulong>(1e9+7);

int main() 
{
    ulong N;
    cin>>N;
    vector<ulong>A(N);
    vector<ulong>sum(N+1,0);
    for (size_t i = 0; i < N; i++)
    {
        cin>>A[i];
        sum[i+1]=sum[i]+A[i];
    }

    ulong ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        ulong s=(sum[N]-sum[i+1])%mod;
        ans += A[i] * s;
		ans %= mod;
    }

    cout<<ans<<endl;

    return 0;
}