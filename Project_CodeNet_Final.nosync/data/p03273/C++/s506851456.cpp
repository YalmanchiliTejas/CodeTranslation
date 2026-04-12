#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    string s[n];
    int ar[n]={0};
    int br[m]={0};
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        int f=0;
        for(int j=0;j<m;++j)
        {
            if(s[i][j]=='#'){f=1;}
        }
        if(f==0){ar[i]=1;}
    }
    for(int j=0;j<m;++j)
    {
        int f=0;
        for(int i=0;i<n;++i)
        {
            if(s[i][j]=='#'){f=1;}
        }
        if(f==0){br[j]=1;}
    }
    for(int i=0;i<n;++i)
    {
        if(ar[i]==0)
        {
            for(int j=0;j<m;++j)
            {
                if(br[j]==0)
                {
                    cout<<s[i][j];
                }
            }
            cout<<endl;
        }
    }

return(0);
}