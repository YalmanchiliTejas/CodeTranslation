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
ll n,m,T,k,q,x;

vector<ll> A;
ll ans = 0;
bool done = 0;
ll l = 0;

void doit(){
    sort(all(A));
    if(done)return;
    if(A[n-1] < n){
        done = 1;
        return;
    }
    ans++;
    A[n-1]-=n;
    for(ll c1 = 0; c1 < n-1; c1++){
        A[c1]++;
    }
}

void solve(){
    sort(all(A));
    if(done)return;
    if(A[n-1] < n){
        done = 1;
        return;
    }
    l = n-1;
    if(l > 0){
        while(A[l-1] >= A[n-1]-n-1){
            l--;
            if(l == 0)break;
        }
    }
    ll c = n-l;
   // cout << ans << " " << l << "\n";
    if(l == 0){

        k = max(0ll,A[n-1] - 2*n - 3);
        ans += n*k;
        for(ll c1 = 0; c1 < n; c1++){
            A[c1] -= k;
        }
        while(!done){
            doit();
        }
    }
    else{
        k = max((A[n-1] - A[l-1])/(n+1) - 2*(n+2) , 0ll);
        k = min(k, (A[l] - n + 0) / (n - c + 1) - 2*(n+1));
        k = max(k,0ll);
        ans += k*c;
        for(ll c1 = 0; c1 < l; c1++){
            A[c1] += k*c;
        }
        for(ll c1 = l; c1 < n; c1++){
            A[c1] -= k*(n-c+1);
        }
        for(ll c1 = 0; c1 < 10000; c1++){
            doit();
        }
        solve();
    }
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;


    cin >> n;
    l = n-1;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    solve();
    cout << ans << "\n";


    return 0;
}
