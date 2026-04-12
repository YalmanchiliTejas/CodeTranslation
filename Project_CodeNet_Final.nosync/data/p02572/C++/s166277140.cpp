/* /\ In The Name of ALLAH /\
    Author : Jawahiir Nabhan */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 2e5 + 10;
const int MOD = 1e9 + 7;

ll a[N],b[N];
int main()
{
    int n; cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        b[i] = a[i];
        if(i) a[i] += a[i-1];
    }

    ll res = 0;
    for(int i = 0;i < n;i++)
    {
        res += (((a[n - 1] - a[i]) % MOD)*(b[i] % MOD))%MOD;
    }
    //(res %= MOD) += b[n-1]%MOD;
    cout<<res%MOD<<endl;
}
