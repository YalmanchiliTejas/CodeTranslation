#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uu unsigned
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mkp make_pair
#define ss second
#define ff first
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define pb push_back
#define pf push_front
#define printcas cout<<"Case "<<cas<<": "
#define _ continue;
#define endl '\n'
#define __ cout<<endl;continue;
#define vc4d(nam,type,a,b,c,d,fix) vector<vector<vector<vector<type>>>> nam(a,vector<vector<vector<type>>>(b,vector<vector<type>>(c,vector<type>(d,fix))))
const ll oo=(1ll<<60);
int gg(){
    int x=0,w=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')w=0,ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return w?x:-x;
}
ll m(ll& a)
{
   return a= a%MOD;
}
int main()
{
     io;
    int T=1;
    //T=gg();
    //cin>>T;
    //for(int cas=1;cas<=T;cas++)
    while(T--)
    {
       ll n,i,j,k,l,sum,ans;
       cin>>n;
       vl v(n);
       for(auto &x:v)cin>>x;
       sum=v[n-1]+v[n-2];ans=v[n-2]*v[n-1];m(ans);m(sum);
       for(i=n-3;i>-1;i--)
       {
           k=v[i]*sum;
           ans+=k;
           m(ans);
           sum+=v[i];
           m(sum);
       }
       cout<<m(ans);
    }
    return 0;
}
