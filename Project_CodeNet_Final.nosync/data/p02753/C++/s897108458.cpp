#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define ll long long int
#define INF INT_MAX
#define mod
#define chutiyaap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.second < b.second);}
ll gcd(ll a, ll b){if(a==0)return b;return gcd(b % a, a);}
int main()
{
	chutiyaap;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='A')a++;
        else b++;
    }
    if(a!=0&&b!=0)cout<<"Yes";
    else cout<<"No";
}