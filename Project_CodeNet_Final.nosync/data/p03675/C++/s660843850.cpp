#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;

ll ANS[1000001] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    vector<ll> A;

    cin >> n;

    ll l = 0;
    ll r = n-1;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    for(ll c1 = n-1; c1 >= 0; c1--){
        if((n-c1-1)%2 == 0){
            ANS[l] = A[c1];
            l++;
        }
        else{
            ANS[r] = A[c1];
            r--;
        }
    }

    for(ll c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}

