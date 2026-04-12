#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=50000;
ll mod=1e9+7;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define endl '\n'
#define pb push_back
#define se second
#define fi first
#define maxe max_element
#define mine min_element
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define boost  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long expo(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*expo((x*x)%M,(n-1)/2,M))%M;

}

bool prime[10000001];
void fin()
{
    for(int i=2;i*i<=1000000;i++)
    {
        if(!prime[i])
        for(int j=i*i;j<=1000000;j+=i)
            prime[j]=true;
    }
}


void solve()
{
    string s;
    cin>>s;
    ll a=0,b=0,n=s.length();
    //debug(n);
    for(int i=0;i<n;i++)if(s[i]=='A')a++;else b++;
   // debug2(a,b);
    if(a!=0 && b!=0)
        cout<<"Yes";
    else
        cout<<"No";
}

int main(){
    boost;
  solve();
}
