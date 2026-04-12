#include <bits/stdc++.h>
 
using namespace std;
 
#define BOOST        std::ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define sp           <<" "<<
#define ll           long long
#define ld           long double
#define AZI(i,x)     for(auto i=x.begin();i!=x.end();i++)
#define AZ(x)        x.begin(),x.end()
#define P(x,y)       pair < x,y >
#define V(x)         vector < x >
#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define PI           3.14159265358979323846264338327950288419716939937510
 
const ll mod=1e9+7,N=1e5+5,INF = 1e18;

int n,k;
ll a[3005];
ll dp[3005][3005]={}; 
bool chk[3005][3005]={}; 

ll deq(int i1,int i2,bool turn)
{
    if(i1>i2)
        return 0;
    
    if(chk[i1][i2])
        return dp[i1][i2];

    chk[i1][i2] = 1;
    
    if(turn)
        return dp[i1][i2] = i1==i2 ? a[i1]:max( a[i1] + deq(i1+1,i2,!turn), a[i2] + deq(i1,i2-1,!turn));

    else
        return dp[i1][i2] = i1==i2 ? -a[i1]:min( -a[i1] + deq(i1+1,i2,!turn), -a[i2] + deq(i1,i2-1,!turn));
}

int main() 
{ 
    BOOST

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];
    
    cout<<deq(0,n-1,1)<<"\n";
    
    return 0;    
} 
