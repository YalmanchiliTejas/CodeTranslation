#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map <int, int> u;
int seg[1000005];
int ima[1000005];
int niz[1000005];

void add(int node, int l, int r, int x){
    if(l == r){
        ima[l]++;
        seg[node] = x;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) add(node*2, l, mid, x);
    else add(node*2+1, mid+1, r, x);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

void rem(int node, int l, int r, int x){
    if(l == r){
        ima[l]--;
        if(ima[l] == 0) seg[node] = 0;
        else seg[node] = x;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) rem(node*2, l, mid, x);
    else rem(node*2+1, mid+1, r, x);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

int query(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr){
        return seg[node];
    }
    int mid = (l+r)/2;
    return max(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n;
    cin >> n;
    vector <int> vec;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        vec.push_back(niz[i]);
    }
    sort(vec.begin(), vec.end());
    int cnt = 0;
    for(auto c : vec){
        if(!u[c]) u[c] = ++cnt;
    }
    for(int i=1; i<=n; i++){
        niz[i] = u[niz[i]];
    }
    int g = 0;
    for(int i=1; i<=n; i++){
        int x = query(1, 1, n, 1, niz[i]-1);
        if(x != 0) rem(1, 1, n, x);
        else g++;
        add(1, 1, n, niz[i]);
    }
    cout << g;
    return 0;
}
