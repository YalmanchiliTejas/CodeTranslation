#include<bits/stdc++.h>
#define pb           push_back
#define pf           push_front
#define in           insert
#define ff           first
#define ss           second
#define int          long long
#define rep(i,x,m)   for(int i=x;i<m;i++)
#define repr(i,x,m)  for(int i=x;i>=m;i--)
#define MOD          1000000007
#define endl         "\n"
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define vi           vector<int>
#define pi           pair<int,int>
#define sz(x)       (int)x.size()
#define pq           priority_queue<int>
#define pqs          priority_queue<int,vi,greater<int> >
#define fix(y)       fixed<<setprecision(y)
#define print(v)     for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl
#define FIO         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int fac[2000005]={0};
void factorial(){ fac[0]=1; fac[1]=1; for(int i=2;i<200005;i++) fac[i]=((i%MOD)*(fac[i-1]%MOD))%MOD;}
int power(int n,int m)
{int p=1;if(m==0)return 1;p=(power(n,m/2)%MOD);p=(p%MOD*p%MOD)%MOD;
return(m&1?((p%MOD*n%MOD)%MOD):(p%MOD));}
int ncr(int n,int r){return ((fac[n]*power(fac[r],MOD-2))%MOD*power(fac[n-r],MOD-2))%MOD;}

void ram5564()
{
     
 int n;
 cin>>n;
 if(n>=30)
 {
    cout<<"Yes\n";return;
 }
 cout<<"No\n";
}

signed main()
{
        FIO
          
        
        int t=1;
       // cin>>t;
        while(t--)
        ram5564();
        cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;

        return 0;
}