#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
    }

    vector<int> suffix(n);
    suffix[n-1] = v[n-1];
    for(int i = n-2;i>=0;i--)
    {
        suffix[i] = (v[i] + suffix[i+1]) % mod;
    }

    int total = 0;
    for(int i = 0;i<n-1;i++)
    {
        int t = (long long) suffix[i+1] * v[i] % mod;
        total = (total + t) % mod;
    }

    cout<<total<<"\n";

    return 0;
}