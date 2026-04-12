#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define M 1000000007
#define pb push_back
#define fs first
#define se second
using namespace std;
int main()
{
    ll n,k;
    cin>>n;
    string s;
    cin>>s;
    cin>>k;
    char ch=s[k-1];
    for(ll i=0;i<n;i++)
        if(ch!=s[i])
            s[i]='*';
    cout<<s<<endl;
}
