#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define mods 1000000009

vector<int>v1[100100];
int ans=0;
int mm;
int ar[100100];

int dfs(int x,int cn)
{
    if(ar[x]==1)
    return 0;
    ar[x]=1;
    if(cn==mm)
    {
        ar[x]=0;
        ans++;
        return 0;
    }
    for(int i=0;i<v1[x].size();i++)
    {
        dfs(v1[x][i],cn+1);

    }
    ar[x]=0;

}

int main()
{
   // factorila();
    //freopen("amin.txt","w",stdout)
     int n,cn=1,a,b,i,j,l,k,k1,m,x,y;
     map<int,int>m1;
     scanf("%d",&n);
     scanf("%d",&m);
     for(i=0;i<m;i++)
     {
         cin>>x>>y;
         v1[x].push_back(y);
         v1[y].push_back(x);

     }

     mm=n;

     dfs(1,1);
     cout<<ans<<"\n";
}
