#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18+5

struct node{

    node *l, *r;
    int lazy, val;

    void push(){
        if(lazy){

            if(l) l->lazy += lazy;
            if(r) r->lazy += lazy;
            val += lazy;
            lazy = 0;

        }
    }

    void add(int x){

        lazy += x;

    }

    void Merge(){

        val = INF;
        if(l) val = min(val, l->val);
        if(r) val = min(val, r->val);

    }
};


int n, m;


void Build(node *root, int l, int r){

    if(l == r){

        return;

    }

    int mid = (l+r)/2;
    root->l = new node{NULL,NULL,0,0};
    root->r = new node{NULL,NULL,0,0};

    Build(root->l, l, mid);
    Build(root->r, mid+1, r);
}

void add(node* root, int l, int r, int ql, int qr, int val){

    root->push();

    if(l > qr || r < ql) return;

    if(l >= ql && r <= qr){

        root->add(val);
        root->push();
        return;

    }

    int mid = (l+r)/2;

    add(root->l, l, mid, ql, qr, val);
    add(root->r, mid+1, r, ql, qr, val);

    root->Merge();
}

signed main(){

    cin >> n >> m;

    vector< pair<int, int> > intervals[n+1];

    node *root = new node{NULL, NULL, 0,0};

    Build(root, 0, n);

    int sum = 0;

    for(int i = 0; i < m; i++){

        int a, b, c;
        cin >> a >> b >> c;

        intervals[b].push_back({a,c});
        sum += c;

    }

    int ans = 0;

    for(int i = 1; i <= n+1; i++){

        for(auto a : intervals[i-1]){

            add(root, 0, n, 0, a.first-1, a.second);

        }

        root->push();
        int best = root->val;
        if(i == n+1) ans = best;

        add(root, 0, n, i, i, best);

    }

    cout << sum - ans << endl;
}
