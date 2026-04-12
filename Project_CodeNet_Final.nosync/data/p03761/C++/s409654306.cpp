#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
struct node
{
    char a[60];
    int b[30];
} c[60];
char d[3000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int i,j,k,m,n,o;
    int flag=0;
    int T;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>c[i].a;
        n=strlen(c[i].a);
        for(j=0; j<n; j++)
            c[i].b[c[i].a[j]-'a']++;
    }
    int ans=0;
    for(i=0; i<26; i++)
    {
        flag=0;
        m=99999;
        for(j=1; j<=T; j++)
        {

            if(c[j].b[i]==0)
            {
                flag=1;
                break;
            }
            else
            m=min(m,c[j].b[i]);
        }
        if(flag==0)
        {
            for(k=0; k<m; k++)
                d[ans++]='a'+i;
        }
    }
    cout<<d<<endl;
    return 0;
}
