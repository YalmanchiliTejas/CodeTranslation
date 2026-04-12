#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define mp          make_pair
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
// #define vb          vector<bool>
// #define vc          vector<char>
#define vii         vector<pii>
//#define mi          map<int,int>
//#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
// #define ub(x)       upper_bound(x)
// #define lb(x)       lower_bound(x)
#define endl        '\n'
#define file        freopen("b1.in","r",stdin);freopen("output.txt","w",stdout)
#define fastio      ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// #define N            1e5+5
// #define M           1e9+7
#define MAX         50000
#define mem0(a)     memset(a,0,sizeof(a))
#define prec        cout<<std::setprecision(9)<<std::fixed
#define forn(i,a,b)  for(int i=a;i<b;i++)
#define pi          3.14159265358979323

struct cmp { 
    bool operator() (pii a,pii b){
        return ((a.F-a.F/2)*a.S)<((b.F-b.F/2)*b.S);
    }
};
// priority_queue<pii,vector<pii>,cmp> q;
// 437235829
const int N=1e5+1;
int n,m,k;

const int MOD=1e9+7;

void Anon_mouS(){
    int n;
    long long cur = 0;
    long long sol = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        sol = (sol + input*cur%MOD) % MOD;
        cur = (cur + input) % MOD;
    }
    cout<<sol<<endl;
}
int32_t main(){
    fastio;
    int q=1;
    // sieve();
    // cin>>q;
    for(int it=1;it<=q;it++){
        // cout<<"Case #"<<it<<": ";
        Anon_mouS();
    }
    return 0;   
}