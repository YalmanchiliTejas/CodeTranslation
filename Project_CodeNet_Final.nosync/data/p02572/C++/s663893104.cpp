

    #include <bits/stdc++.h> 
    //#define M_PI 3.14159265358979323846



using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define repb(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define vc vector<char>
#define vld vector<ld>
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
#define vvld vector<vector<ld> >
#define vpii vector<pii>
#define vpll vector<pll>
#define ld long double
#define ll long long
#define sz(a) (ll)a.size()
#define ssortA(arr)   stable_sort(arr.begin(),arr.end())
#define ssortB(arr)   stable_sort(arr.begin(),arr.end(),greater<ll >());
#define pii pair<int,int>
#define pll pair<long long,long long>
#define ff first
#define ss second
#define search(arr,c)  binary_search(arr.begin(),arr.end(),c)
#define pb   push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define endl "\n" 
#define PI acos(-1.0)
#define GCD(a,b) __gcd(a,b)
#define popcount(x) __builtin_popcountll(x)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define r1(x) cin>>x
#define r2(x,y) cin>>x>>y
#define r3(x,y,z) cin>>x>>y>>z
#define r4(a,b,c,d) cin>>a>>b>>c>>d
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define fix(f,n) fixed<<setprecision(n)<<f<<endl
#define check(ds, a) (ds.find(a)!=ds.end()?1:0)
#define mem(arr)  memset(arr,0,sizeof(arr))
const int M=(int)1e9+7;
int main(){
    int n;cin>>n;
    vl arr(n);
    rep(i,0,n){r1(arr[i]);}
    vl suf(n,0);suf[n-1]=0;
    repb(i,n-2,0){
        suf[i]=(suf[i+1]+arr[i+1])%M;
    }
    ll res=0;
    rep(i,0,n-1){
        ll pro=(arr[i]*suf[i])%M;
        res=(res+pro)%M;
    }
    cout<<res<<endl;
}