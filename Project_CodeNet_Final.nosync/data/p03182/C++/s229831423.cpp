#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




//source: https://atcoder.jp/contests/dp/tasks/dp_w
// W: Intervals




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



const ll inf = 2e18;

////////////////////////////////////////////////////////////////////////////////////
ll t[maxn*4], o[maxn*4];

void push(int v) {
    t[2*v]+=o[v];
    t[2*v+1]+=o[v];
    o[2*v]+=o[v];
    o[2*v+1]+=o[v];
    o[v]=0;
}

ll queryMin(int v, int tl, int tr, int l, int r) {
    if (l>tr||r<tl) return inf;
    if (l<=tl&&tr<=r) {
	return t[v];
    } else {
	push(v);
	int tm=(tl+tr)/2;
	return min(queryMin(2*v,tl,tm,l,r),queryMin(2*v+1,tm+1,tr,l,r));
    }
}

void rangeAdd(int v, int tl, int tr, int l, int r, ll dx) {
    if (l>r) return;
    if (l>tr||r<tl) return;
    if (l<=tl&&tr<=r) {
	t[v]+=dx;
	o[v]+=dx;
    } else {
	push(v);
	int tm=(tl+tr)/2;
	rangeAdd(2*v,tl,tm,l,r,dx);
	rangeAdd(2*v+1,tm+1,tr,l,r,dx);
	t[v]=min(t[2*v],t[2*v+1]);
    }
}


//0-indexed helpers
//upd(l,r,dx): add dx on range [l,r]
//qry(l,r): query for min on range [l,r]
//edit(i,val): edit index i to be val

void upd(int l, int r, ll dx) {
    if (l>r) return;
    rangeAdd(1,1,maxn,l+1,r+1,dx);
}

ll qry(int l, int r) {
    assert(l<=r);
    return queryMin(1,1,maxn,l+1,r+1);
}

void edit(int i, ll val) {
    upd(i,i,val-qry(i,i));
}
////////////////////////////////////////////////////////////////////////////////////



vector<pair<int,int>> intervals[maxn];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n, m; cin>>n>>m;
    ll tot=0;
    
    while (m--) {
	int l,r,a; cin>>l>>r>>a;
	tot += a;
	intervals[r].push_back({l,a});
    }


    //dp[i]: given we set ith index to 1, find min prefix representing not taking an interval.
    //as we scan past right border of intervals (that become deactivated), penalize dp values
    //that are before left border of recently deactivated interval.

    //dp[0]: we took none of the intervals
    
    upd(0,n+1,inf);
    edit(0,0);

    for (int i=1; i<=n+1; i++) {
	for (auto p: intervals[i-1]) {
	    upd(0,p.first-1,p.second);
	}
	ll dp = qry(0,i);
	edit(i,dp);
    }

    ll res = tot - qry(0,n+1);
    cout<<res<<endl;
    return 0;
}
