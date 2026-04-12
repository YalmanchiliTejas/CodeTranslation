///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int h,w;
string s[10];
int nd=0;
void rec(int x,int y,int cnt)
{
      if(x<0 || y<0 || x>=h || y>=w)return ;
      if(x==h-1 && y==w-1)
      {
          if(s[x][y]=='#')cnt++;
          if(nd==cnt)
          {
              cout<<"Possible"<<endl;
              exit(0);
          }
          return ;
      }
      if(s[x][y]=='#')cnt++;
      rec(x+1,y,cnt);
      rec(x,y+1,cnt);
}
 main()

{
    fast
    cin>>h>>w;
    f(i,0,h-1)cin>>s[i];
    f(i,0,h-1)
    {
        f(j,0,w-1)
        {
            if(s[i][j]=='#')nd++;
        }
    }
    rec(0,0,0);
    cout<<"Impossible"<<endl;
    return 0;

}



































