#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k;



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
    vl A;
    vl A2;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        A2.push_back(a);
    }
    sort(all(A2));
    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] <= A2[n/2-1]){
            cout << A2[n/2]<< "\n";
        }
        else{
            cout << A2[n/2-1] << "\n";
        }
    }

    return 0;
}
