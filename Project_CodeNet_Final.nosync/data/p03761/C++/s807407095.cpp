//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=110;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n;
string s[N],ot;
signed main()
{
    cin>>n;
    for(ri int i=1;i<=n;i++) cin>>s[i];
    for(ri char i='a';i<='z';i++)
    {
        int qwq=1;
        for(ri int j=1;j<=n;j++) if(s[j].find(i)==-1) { qwq=0; break; }
        if(!qwq) continue;
        int pp=1e18;
        for(ri int j=1;j<=n;j++)
        {
            int cnt=0;
            for(ri int k=0;k<(int)s[j].size();k++)
                cnt+=(s[j][k]==i);
            pp=min(pp,cnt);
        }
        for(ri int j=1;j<=pp;j++) ot+=i;
    }
    cout<<ot<<endl;
    return 0;
}