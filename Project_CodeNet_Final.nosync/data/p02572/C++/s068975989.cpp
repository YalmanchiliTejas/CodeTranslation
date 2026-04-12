#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef vector<lld> vll;
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define srt(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define mod 1000000007
#define pi 3.1415926535
lld a,b,c,d,e,f,g,h,i,j,k=0,l=0,m=1,n=1,o,q=0,r=0,u,v,w,x,y,z,s,t,p=0;
lld temp=0,ans=0;
double f1,f2,f3,f4,f5,f6;
char c2,c3,c4,c5,c6;
vll v11;
pair<lld,lld>p1,p2,p3;
map<lld,lld>mv;bool a12[200005],a13[200005];
bool b11[500006],c11[500006];lld a11[500006];
lld gcd(lld a, lld b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}
void dfs(lld i,vector<lld>vg[])
{
    if(b11[i]==true)    return;
    p++;
    b11[i]=true;
    for(auto x11:vg[i])
    {
        if(b11[x11]==false)
        {
            dfs(x11,vg);
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  t=1;
  //cin>>t;
  while(t--)
  {
    string s3,s1,s2;
    cin>>n;
    //lld p1,q1,a1,b1,c1,d1;
    lld a1[n+1]={0},b1[n],c1[n+1];vector<lld>vg[n+1];
    map<lld,lld>m1,m2;queue<lld>q2;vll v1,v2;p=q=0;
    rep(i,0,n)
    {
        cin>>a1[i];
    }
    b1[n-1]=0;
    for(i=n-2;i>-1;i--)
    {
        b1[i]=(b1[i+1]+a1[i+1])%mod;
    }
    for(i=0;i<n;i++)
    {
        p=p+(a1[i]*b1[i])%mod;
        p=p%mod;
    }
    cout<<(p);
    cout<<endl;
  }
  return 0;
}