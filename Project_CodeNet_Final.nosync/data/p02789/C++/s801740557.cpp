#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
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
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;

int main() {
 
    cin.sync_with_stdio(0); cin.tie(0); 
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        if(n==m){
            cout<<"Yes";
        }
        else
            cout<<"No";
    }
    return 0;   
}