#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;

static const int MAX_SIZE = 1 << 20; 

LL segMax[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

//区間[a, b)に値xを加算する.
void add(int a, int b, LL x, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return;

    if (a <= l && r <= b){
        segAdd[k] += x;
        return;
    }

    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);

    segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
}

LL getMax(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return 0;

    if (a <= l && r <= b) return (segMax[k] + segAdd[k]);

    LL left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
    LL right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);

    return (max(left, right) + segAdd[k]);
}

vector<P> v[200001];

int main(){
    int n,m;cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l,r,a;cin >> l >> r >> a;
        v[r].pb(make_pair(l,a));
    }
    for (int i = 0; i <= n; i++) {
        add(i,i+1,getMax(0,i));
        for (int j = 0; j < v[i].size(); j++) {
            add(v[i][j].fs,i+1,v[i][j].sc);
        }
    }
    cout << getMax(0,n+1) << endl;
    return 0;

}
