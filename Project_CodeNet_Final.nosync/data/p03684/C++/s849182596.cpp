#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i<r;i++)
#define dec(i, l, r) for (int i = l; i>=r;i--)
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pb(c) push_back(c)
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define mp(i, j) make_pair(i,j)
#define ull unsigned long long int
#define ll  long long int
#define pie 3.141592653589793238
#define inf ((ll)1e18)
#define eps 1e-14
#define mod ((int)1e9+7)
#define maxlg 18
#define maxn 1000002
#define left(i) ((i)<<1)
#define right(i) (((i)<<1)+1)
int dsuPar[maxn];
int rnk[maxn];
int find(int x) {
    if (dsuPar[x]==x)return x;
      return find(dsuPar[x]);
}

int merge(int x,int y) {
    int parx =  find(x);
    int pary = find(y);
    if (rnk[parx]==rnk[pary]) {
        dsuPar[pary] = parx;
        rnk[parx]++;
    } else if (rnk[parx]<rnk[pary]) {
        dsuPar[parx] = pary;
    } else {
        dsuPar[pary] = parx;
    }
}
vii x,y;
ii point[maxn];
struct s{
    int diff,i,j;
};
bool comp(s a,s b) {
    if (a.diff==b.diff && a.i==b.i)
        return a.j<b.j;
    if (a.diff==b.diff) {
        return a.i<b.i;
    }
    return a.diff<b.diff;
}
set<s,bool(*)(s,s)> q(comp);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 #endif
     int n;
    cin>>n;
    rep (i,0,n) {
        int a,b;
        dsuPar[i]=i;
        cin>>a>>b;
        point[i] = mp(a,b);
        x.push_back(mp(a,i));
        y.push_back(mp(b,i));
    }
    sort(all(x));
    sort(all(y));
    rep (i,0,n-1) {
        s t= {abs(x[i].first-x[i+1].first),x[i].second,x[i+1].second};
        s t1 = {abs(y[i].first-y[i+1].first),y[i].second,y[i+1].second};

        q.insert(t);
        q.insert(t1);
    }
    ll ans=0;

    while (!q.empty()) {
        s top = *q.begin();
        q.erase(q.begin());
        if (find(top.i)!=find(top.j)) {
            merge(top.i,top.j);
            ans+=top.diff;
        }
    }
    cout<<ans;
    return 0;
}