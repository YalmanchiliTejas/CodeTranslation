#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back

using namespace std;

const ll N=1e4+5;

ll mod=1e9+7;
ll mem[N][105][2],n;
int d;

string k;

ll dp(int pos,int m,bool flag)
{
    if (pos==n)
    {
        return (m==0);
    }
    if (mem[pos][m][flag]!=-1)return mem[pos][m][flag];
    ll ans=0;
    for (int i=0;i<=(flag?9:(k[pos]-'0'));i++)
    {
        ans+=dp(pos+1,(m+i)%d,flag|i<(k[pos]-'0'));
        ans%=mod;
    }
    ans%=mod;
    return mem[pos][m][flag]=ans;
}

int main()
{
    memset(mem,-1,sizeof mem);
    cin >> k >> d;
    n=k.length();
    ll ans=dp(0,0,0)-1;
    if (ans==-1)ans=mod-1;
    cout << ans << endl;
    return 0;
}
