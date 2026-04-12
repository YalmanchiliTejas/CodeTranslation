#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>b;i--)

#define pb push_back
#define mp make_pair
#define all(A) A.begin(),A.end()
#define allr(A) A.rbegin(),A.rend()
#define precise(i) fixed << setprecision(i)
#define fi first
#define se second

#define err() cout<<"\n==================================\n";
#define errA(A) for(auto i:A) cout<<i<<" "; cout<<"\n";
#define err1(a) cout<<#a<<" "<<a<<"\n";
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n";
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n";
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<"\n";

const int logN = 20;
const int M = 1000000007;
const int INF = 1e12;
#define PI 3.14159265;
const int N = 200005;

#define Pii pair<int,int>
#define Vi vector<int>
#define Vpii vector<Pii>

void solve()
{
       int n;
       cin>>n;
       Vi a(n);
       rep(c,0,n)
       {
              cin>>a[c];
       }
       int s1=0, s2=0;
       rep(c,0,n)
       {
              s1+=(a[c]);
              s1%=M;
       }
       s1=(s1)*(s1);
       s1%=M;
       rep(c,0,n)
       {
              s2+=(((a[c])*(a[c]))%M);
              s2%=M;
       }
       int s=s1-s2;
       if(s<0)
       {
              s+=M;
       }
       if(s%2==0)
       {
              cout<<s/2;
       }
       else
       {
              cout<<(s+M)/2;
       }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
    {
           solve();
    }
    return 0;
}