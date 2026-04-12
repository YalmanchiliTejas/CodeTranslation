#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[k-1])
        {
            s[i] = '*';
        }
    }
    cout<<s;
    return 0;
}
