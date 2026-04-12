#include<bits/stdc++.h>

using namespace std;

#define io freopen("test.txt", "r", stdin);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);


#define ull unsigned long long int
#define lli long long int
#define li long int
#define ld long double

#define cout(x) cout<<x<<" "
#define coutn(x) cout<<x<<endl
#define newline cout<<endl

#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define ar array

#define pii pair<int,int>
#define pll pair<lli,lli>
#define pps pair<pair<int,int>, string>

const int MOD=1e9+7;
const lli INF=1e18;
const int MX=100001;
const int N=1000000;

int main(){
    fast   

    lli n,sum=0;
    cin>>n;
    
    vector<lli>v(n);
    vector<lli>p(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    p[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--) p[i]=v[i]+p[i+1];

    lli ans=0;
    for(int i=0;i<n-1;i++){
        ans=(ans + (v[i]%MOD)*(p[i+1]%MOD)%MOD)%MOD;
    }
    cout<<ans%MOD<<"\n";

    return 0;
}