///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100009;
string s;
int k,n;
int dp[103][4][2];
int solve(int pos,int cnt,int is_sml)
{
    if(cnt>k)return 0;
    if(pos>=n)
    {
        if(cnt==k)return 1;
        else return 0;
    }
    int &ret=dp[pos][cnt][is_sml];
    if(ret!=(-1))return ret;
    ret=0;
    if(is_sml)
    {
        ret+=solve(pos+1,cnt,is_sml);
        int x=solve(pos+1,cnt+1,is_sml);
        x=9*x;
        ret+=x;
    }
    else
    {
         int dg=s[pos]-'0';
         f(i,0,dg-1)
         {
             if(i==0)ret+=solve(pos+1,cnt,1);
             else ret+=solve(pos+1,cnt+1,1);
         }
         if(dg==0)ret+=solve(pos+1,cnt,is_sml);
         else ret+=solve(pos+1,cnt+1,is_sml);
    }
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>s>>k;
    n=s.size();
    cout<<solve(0,0,0)<<endl;
    return 0;

}



































