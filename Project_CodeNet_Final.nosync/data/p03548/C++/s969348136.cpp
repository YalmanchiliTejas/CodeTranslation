#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size)
#define MOD 1000000007
const long long mod = 1e9+7;
typedef vector<long long> Vl;
typedef vector<double> VI;  // VI a(n);
typedef vector<string> VS;  
typedef vector<VS> VSS;  
typedef vector<VI> VVI;   // VVI a(n,vector<int>(m)) n * m 
typedef vector<Vl> VVl;
typedef pair<int, int> PII;
typedef long long ll;  //ll とdoubleは違う
// cout << << endl;
// cin >> ;
int main(){
    ll a,b,c=0,d=0,n,m1,n2,m2,min=100000,k=0,ans=0;
    string s,s2;
    cin >> a >> b >> c;
    ans = a / (b+c);
    if(a-ans*(b+c)==c)
        cout << ans <<endl; 
    else cout << ans-1 <<endl; 
    return 0;
}
