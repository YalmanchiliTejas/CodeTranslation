#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p=1000000007;
int main() {
   
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--){
        string ans="Yes";
        string s;cin>>s;
        if(s=="AAA"||s=="BBB")ans="No";
        cout<<ans<<endl;
    }   
    return 0;   
}   