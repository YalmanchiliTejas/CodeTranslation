#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=1000000;
const ll inf=1e18;
const ll mod=1e9+7;

int main()
{
    FasterIO;
    ll n, m, k;
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    if(s[0]==s[2]) cout<<"No"<<endl;
    else           cout<<"Yes"<<endl;

    return 0;
}

