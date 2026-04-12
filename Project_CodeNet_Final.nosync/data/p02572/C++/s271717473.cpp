/*jai_ganeshdeva*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pu push  //  adds the value to the last of the queue 
#define lld long long int
#define ins insert /// used in set to insert the values 
#define adv advance  /// used to increment the iterator
#define mp make_pair
#define fi first
#define se second
#define all(c) c.begin(),c.end()
#define PI 3.1415926
#define INF (lld)1e18
#define vl  vector<long long int >
#define vpll vector< pair<lld ,lld> >
#define vvl vector<vector<lld> > 
#define pll pair <lld,lld>
lld p1=1e9 + 7,p2=998244353;

void judge(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
}

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


long long int modp(lld a,lld p,lld n)
{
    lld d[100];
    lld i,j,k,l;
    if(n==0) return 1;
    for(i=0;n>=1;i++)
    {
        d[i]=n%2;
        n/=2;
    }
    l=i;
    long long int e=1;
    if(d[0]==1) e*=(a%p);
    for(i=1;i<l;i++)
    {
        a*=a;
        a=a%p;
        if(d[i]==1) 
        {
            e*=a;
            e=e%p;
        }
    }
    return e%p;
}
lld modInverse(lld n, lld p) 
{ 
    return modp(n, p, p-2); 
}

// lld fac[500005]; 

// void getfac(lld p)
// {
//     fac[0] = 1; 
//     for (lld i=1 ; i<=500005; i++) 
//         fac[i] = fac[i-1]*i%p; 
// }    

// long long int nCrmodp(lld n, lld r,lld p) 
// { 
//    // Base case 
//    if (r==0) 
//       return 1; 
     
//     return (fac[n]* modInverse(fac[r], p) % p * 
//             modInverse(fac[n-r], p) % p) % p; 
// }


lld l,r,mid,ans=0;
lld n,i,j,k,g,m;
lld x,y,n1,n2,h,z,c;
lld aa=1;
lld ss=1;

void solve()

{  
    lld p1 = 1e9 +7;
    vector<lld> v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>l;
        v.pb(l);

    }
    ans =0 ;
    x =v[n-1] ;
    for(i=n-2;i>=0;i--)
    {
        ans+= (x*v[i])%p1;
        x+= v[i];
        x%=p1;
        ans%=p1;
    }
    cout<<ans;
}

int main()
{
    // judge();
    fastio();
    lld t=1;
    // cin>>t;
    // lld p1 = 1e9 + 7;
    // getfac(p1);
    for(int i=0;i<t;i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
        // cout<<"\n";
    }
    return 0;
}
