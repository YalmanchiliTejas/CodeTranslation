#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N=200;

string n;

ll k,mem[N][5][2];

ll dp(int pos,int cnt,bool flag)
{
    if (pos==n.length())
    {
        return (cnt==0);
    }
    if (mem[pos][cnt][flag]!=-1)return mem[pos][cnt][flag];
    ll ans=0;
    for (char ch='0';ch<='9';ch++)
    {
        if (ch=='0')ans+=dp(pos+1,cnt,flag||(ch<n[pos]));
        else if (cnt)
        {
            if ((ch>n[pos]&&flag)||ch<=n[pos])ans+=dp(pos+1,cnt-1,flag||(ch<n[pos]));
        }
    }
    return mem[pos][cnt][flag]=ans;
}

int main()
{
    memset(mem,-1,sizeof mem);
    cin >> n >> k;
    cout << dp(0,k,0) << endl;
    return 0;
}

