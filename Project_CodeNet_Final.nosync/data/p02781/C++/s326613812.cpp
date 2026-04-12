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

const int MX=3000;

ll dp[MX][2][10], n;
string s;
ll call(int p, int f, int k)
{
    if(p==n) return !k;
    ll &ret=dp[p][f][k];
    if(!k)   return ret=1;
    if(~ret) return ret;
    ret=0;
    if(f)
    {
        ret+=call(p+1, 1, k);
        for(int i=1; i<10; i++)
        {
            ret+=call(p+1, 1, k-1);
        }
    }
    else
    {
        for(int i=0; i<s[p]-'0'; i++)
        {
            ret+=call(p+1, 1, (i)?k-1:k);
        }
        ret+=call(p+1, f, (s[p]!='0')?k-1:k);
    }
    return ret;
}

int main()
{
    FasterIO;

    int m, k;
    cin>>s>>k; n=s.size();
    mem(dp, -1);
    ll r1=call(0, 0, k);
    cout<<r1<<endl;
    return 0;
}
