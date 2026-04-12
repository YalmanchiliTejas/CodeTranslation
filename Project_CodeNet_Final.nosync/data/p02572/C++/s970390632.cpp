#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    long long zb=0,r=0;
    cin >> n;
    vector<long long> v(n);
    for (int i=0;i<n;i++)
    {
        cin >> v[i];
        zb+=v[i];
    }
    for (int i=n-1;i>=0;i--)
    {
        zb-=v[i];
        r=(r+v[i]*(zb%mod))%mod;
    }
    cout << r%mod;
}
