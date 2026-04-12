#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, ll> pil;

const int INF=0x3f3f3f3f;
const int N=2e5+5;

int n, m, off=1;
vector <pil> poc[N];
vector <pil> kraj[N];
ll tour[3*N], prop[3*N];

void propag(int pos, int lo, int hi) {
    if (prop[pos]==0) return;
    if (pos<off) {
        prop[pos*2]+=prop[pos];
        prop[pos*2+1]+=prop[pos];
        tour[pos]=max(tour[pos*2], tour[pos*2+1])+prop[pos];
    }
}

void update(int pos, int lo, int hi, int a, int b, ll value) {
    //printf("pos == %d, lo == %d, hi == %d, prop[pos]==%lld\n", pos, lo, hi, prop[pos]);
    if (lo>=a && hi<=b) {
        prop[pos]+=value;
        tour[pos]+=value;
        //propag(pos, lo, hi);
        //printf("pos == %d, lo == %d, hi == %d, prop[pos]==%lld, prop[l] == %lld, prop[r] == %lld\n", pos, lo, hi, prop[pos], prop[pos*2], prop[pos*2+1]);
        //printf("tour[pos] == %lld, tour[l] == %lld, tour[r] == %lld\n", tour[pos], tour[pos*2], tour[pos*2+1]);
        return;
    }
    if (hi<=a || lo>=b) return;
    int mid=(lo+hi)/2;
    update(pos*2, lo, mid, a, b, value);
    update(pos*2+1, mid, hi, a, b, value);
    tour[pos]=max(tour[pos*2], tour[pos*2+1])+prop[pos];
}

ll query(int pos, int lo, int hi, int a, int b) {
    //printf("pos == %d, lo == %d, hi == %d, tour[pos] == %d, prop[pos] == %d\n", pos, lo, hi, tour[pos], prop[pos]);
    //propag(pos, lo, hi);
    //printf("tour[pos] == %d, prop[pos] == %d\n", tour[pos], prop[pos]);
    if (lo>=a && hi<=b) return tour[pos];
    if (lo>=b || hi<=a) return -(ll)INF*(ll)INF;
    int mid=(lo+hi)/2;
    return max(query(pos*2, lo, mid, a, b), query(pos*2+1, mid, hi, a, b))+prop[pos];
}

void load() {
    scanf("%d %d", &n, &m);
    while (off<=n) off*=2;
    for (int i=0; i<m; ++i) {
        int l, r; ll a;
        scanf("%d %d %lld", &l, &r, &a);
        poc[l].pb(mp(r, a));
        kraj[r].pb(mp(l, a));
    }
}

void solve() {
    /*for (int i=2*off-1; i>0; --i) {
        tour[i]=0;
        if (i==off) tour[i]=0;
        if (i<off) tour[i]=max(tour[i*2], tour[i*2+1]);
    }*/
    ll sol=0;
    for (int i=1; i<=n; ++i) {
        for (pil p:poc[i]) {
            update(1, 0, off, 0, i, p.Y);
            //printf("updejtam [%d, %d] na %d\n", 0, i, p.Y);
            //system("pause");
        }
        ll res=query(1, 0, off, 0, i);
        //printf("i == %d, res == %lld\n", i, res);
        //system("pause");
        sol=max(sol, res);
        update(1, 0, off, i, i+1, res);
        for (pil p:kraj[i]) update(1, 0, off, 0, p.X, -p.Y);
    }
    printf("%lld\n", sol);
}

int main() {
    load();
    solve();
    return 0;
}
