#include<bits/stdc++.h>
 
using namespace std;
typedef unsigned long long int ll;
const ll hell = 100005; 
bool comp(vector<ll> a, vector<ll> b)
{
    return a[0]<b[0];
}
ll binpow(ll a,ll b) 
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    for(ll i=0; i<s.length()-1; i++)
    {
        if(s[i]!=s[i+1]){
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
    return 0;
}
