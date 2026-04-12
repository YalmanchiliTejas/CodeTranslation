#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
 
 
using namespace std;

#define int long long
#define sc second
#define fr first
 
#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(int (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl
#define MAX 100000
#define NUM 101
 
llong n;
bool used[MAX];
typedef pair<int, int> pii; // (cst, to)
vector<pii> G[MAX];
 
int prim() {
    priority_queue<pii> que;
    fill(used, used + MAX, false);
    que.push(pii(0, 0));
    int ret = 0;
    while (!que.empty()) {
        int  v = que.top().second;
        int cst = (-1)*(que.top().first);
        que.pop();
        if (used[v]) continue;
        used[v] = true;
        ret += cst;
        for (int i = 0; i < G[v].size(); i++)
            que.push(pii((G[v][i].first)*(-1), (G[v][i].second)));
    }
    return ret;
}
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
    pii X[100001], Y[100001];

    for(int i=0; i<n; i++) {
      int a, b;
      cin >> a >> b;
      X[i] = pii(a, i);
      Y[i] = pii(b, i);
    }

    sort(X, X + n);
    sort(Y, Y + n);

    for(int i=0; i<n; i++) {
      if( i != n-1 ) {
	G[X[i].sc].push_back(pii(abs(X[i].fr - X[i + 1].fr), X[i + 1].sc));
	G[Y[i].sc].push_back(pii(abs(Y[i].fr - Y[i + 1].fr), Y[i + 1].sc));
      }
      if( i != 0 ) {
	G[X[i].sc].push_back(pii(abs(X[i].fr - X[i - 1].fr), X[i - 1].sc));
	G[Y[i].sc].push_back(pii(abs(Y[i].fr - Y[i - 1].fr), Y[i - 1].sc));
      }
    }
    
    /* for(int i=0; i<n-1; i++) {
      for(int j=i+1; j<n; j++) {
	if( i == j ) continue;
	G[j].push_back(pii(min(abs(X[i] - X[j]), abs(Y[i] - Y[j])), i));

      }
      }*/
    
    cout << prim() << endl;
 
    return 0;
}
