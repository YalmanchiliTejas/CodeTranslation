#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
typedef long long ll;
string ans[6];
string s;
bool check(string ans)
{
     int y=s.size()-1;
     if(((s[y]=='o'&&ans[y]=='S')||(s[y]=='x'&&ans[y]=='W'))&&ans[y-1]==ans[0])
     {
         return true;
     }
     else if(((s[y]=='o'&&ans[y]=='W')||(s[y]=='x'&&ans[y]=='S'))&&ans[y-1]!=ans[0])
     {
         return true;
     }
     return false;
}

bool check1(string ans)
{
     int y=s.size()-1;
     if(((s[0]=='o'&&ans[0]=='S')||(s[0]=='x'&&ans[0]=='W'))&&ans[y]==ans[1])
     {
         return true;
     }
     else if(((s[0]=='o'&&ans[0]=='W')||(s[0]=='x'&&ans[0]=='S'))&&ans[y]!=ans[1])
     {
         return true;
     }
     return false;
}
int main()
{
    int n,i,j;
    cin>>n>>s;
    ans[1]="SS";
    ans[2]="SW";
    ans[3]="WS";
    ans[4]="WW";
    for(i=1;i<=4;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if((ans[i][j]=='S'&&s[j]=='o')||(ans[i][j]=='W'&&s[j]=='x'))
            {
                ans[i].push_back(ans[i][j-1]);
            }
            else if((ans[i][j]=='S'&&s[j]=='x')||(ans[i][j]=='W'&&s[j]=='o'))
            {
                if(ans[i][j-1]=='S')
                {
                    ans[i].push_back('W');
                }
                else
                {
                    ans[i].push_back('S');
                }
            }
        }
    }
    for(i=1;i<=4;i++)
    {
        if(check(ans[i])&&check1(ans[i]))
        {
            cout<<ans[i]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
