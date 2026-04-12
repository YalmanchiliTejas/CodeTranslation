/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  200019
ll n;
std::vector<ll> a(N);
std::map<pii,ll> zz;
ll func(ll pos,ll rem)
{
    
    if(rem==0)
        return zz[{pos,rem}]=0;
    if(zz.find({pos,rem})!=zz.end())
        return zz[{pos,rem}];       
    if((n-pos+1)<2*rem || pos>=n)
    {
        return zz[{pos,rem}]=-1e18;   
    }    
    ll vl=func(pos+1,rem);
    vl=max(vl,func(pos+2,rem-1)+a[pos]);
    return zz[{pos,rem}] = vl;
}
int main()
{
    
    io    

    cin>>n;
    rep(i,0,n)
    cin>>a[i];
    cout<<func(0,n/2);
    


}