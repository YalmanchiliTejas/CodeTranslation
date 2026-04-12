#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define pi pair <int, int>
#define sz(x) (int)((x).size())
#define int long long

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 2e5 + 11;
const int INF = 2e9;
const ll INF64 = 3e18 + 1;
const double lil = 0.0000000000001;

//ifstream cin ("test.in");
//ofstream cout ("test.out");

int n, m, lazy[4*N], t[4*N];

vector<pi>v[N];

void update(int v, int tl, int tr, int l, int r, int val){

    if(lazy[v] && (tl != tr)){
        t[2*v] += lazy[v];
        lazy[2*v] += lazy[v];
        t[2*v + 1] += lazy[v];
        lazy[2*v + 1] += lazy[v];
        lazy[v] = 0;
    }

    if(l <= tl && tr <= r){

        t[v] += val;
        lazy[v] += val;
        return;
    }

    if(l > tr || r < tl)return;

    int mid = (tl + tr)/2;

    update(2*v, tl, mid, l, r, val);
    update(2*v + 1, mid + 1, tr, l, r, val);

    t[v] = min(t[2*v], t[2*v + 1]);
}

int mn(int v, int tl, int tr, int l, int r){

    if(lazy[v] && (tl != tr)){
        t[2*v] += lazy[v];
        lazy[2*v] += lazy[v];
        t[2*v + 1] += lazy[v];
        lazy[2*v + 1] += lazy[v];
        lazy[v] = 0;
    }

     if(l <= tl && tr <= r)return t[v];

     if(l > tr || r < tl)return INF;

     int mid = (tl + tr)/2;

     return min(mn(2*v, tl, mid, l, r),mn(2*v + 1, mid + 1, tr, l, r));
}



int32_t main(){
ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m;

    int sum = 0;

    for(int i = 1,l,r,val; i <= m; i++){
        cin >> l >> r >> val;
        v[r].pb({l,val});
        sum += val;
    }

    for(int i = 0; i <= 4*n; i++)t[i] = INF;

    update(1,0,n,0,0,-INF);

    int ans = 0;

    for(int i = 1; i <= n + 1; i++){

        for(auto it : v[i - 1]){
            update(1, 0, n, 0, it.ff - 1, it.ss);
        }

        int best = mn(1,0,n,0,n);

        if(i == n + 1)ans = best;

        update(1, 0, n, i, i, best - INF);
    }

    rc(sum - ans);
}