#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 200100;

int n, q;
ll dp[maxn], result;

struct qry {
public:
    int l, r;
    ll value;
};

vector<qry>openings[maxn];
vector<qry>closings[maxn];

ll tree[4*maxn], lazy[4*maxn];

void push_update(int li, int ri, int index) {
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        if(li != ri) {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
}

void update(int ul, int ur, ll uval, int li=0, int ri=n, int index=1) {
    push_update(li, ri, index);
    if(li > ur || ri< ul) return;
    else if(li >= ul && ri <= ur) {
        lazy[index] = uval;
        push_update(li, ri, index);
    }
    else {
        int mid = (li+ri)/2;
        update(ul,ur,uval,li,mid,2*index);
        update(ul,ur,uval,mid+1,ri,2*index+1);
        tree[index] = max(tree[2*index], tree[2*index+1]);
    }
}

ll query(int ql, int qr, int li=0, int ri=n, int index=1) {
    push_update(li, ri, index);
    if(li > qr || ri < ql) return LLONG_MIN;
    else if(li >= ql && ri <= qr) return tree[index];
    else {
        int mid = (li+ri)/2;
        ll a = query(ql,qr,li,mid,2*index);
        ll b = query(ql,qr,mid+1,ri,2*index+1);
        tree[index] = max(tree[2*index], tree[2*index+1]);
        return max(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    qry x;
    for(int i=1;i<=q;i++) {
        cin>>x.l>>x.r>>x.value;
        openings[x.l].pb(x);
        closings[x.r].pb(x);
    }

    for(int i=1;i<=n;i++) {
        for(auto x:openings[i]) {
            update(0, x.l-1, x.value);
        }

        dp[i] = query(0, i-1);
        update(i, i, dp[i]);

        result = max(result, dp[i]);

        for(auto x:closings[i]) {
            update(0, x.l-1, -x.value);
        }
    }
    cout<<result<<"\n";
    return 0;
}