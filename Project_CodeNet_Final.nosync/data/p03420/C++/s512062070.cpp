#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define SORTG(v) sort(v.begin(),v.end(),greater<>())
#define SORT(v) sort(v.begin(),v.end())
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/3

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<string> Vs;

template<class T> void chmax(T& a, T b) {if(a<b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a>b){a=b;}}
void YesNo(int a){cout<<((a)?"Yes":"No")<<endl;}
void YESNO(int a){cout<<((a)?"YES":"NO")<<endl;}
void AorB(int a,string b,string c){cout<<((a)?b:c)<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void start(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);}

signed main(){start();
    int n,k,ans=0;
    cin>>n>>k;
    if(k==0){cout<<n*n<<endl;return 0;}
    REP(i,k+1,n+1){
        ans += (n/i)*(i-k);
        ans += max(0ll,n%i-k+1);
    }
    cout<<ans<<endl;
    return 0;
}
