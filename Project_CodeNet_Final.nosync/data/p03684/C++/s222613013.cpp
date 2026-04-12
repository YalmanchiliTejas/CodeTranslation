#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
#include<numeric>
using namespace std;
typedef long long int lli;
#define rep(i,n) for(lli i = 0;i<((lli)(n));i++)
#define reg(i,a,b) for(lli i = ((lli)(a));i<=((lli)(b));i++)
#define irep(i,n) for(lli i = ((lli)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(lli i = ((lli)(b));i>=((lli)(a));i--)
typedef pair<lli, lli> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprllif(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

struct UF {
	int n;
	vector<int> d;
	UF() {}
	UF(int n):n(n), d(n, -1) {}
	int root(int v){
		if (d[v] < 0) return v;
		return d[v] = root(d[v]);
	}
	bool unite(int x, int y){
		x = root(x); y = root(y);
		if (x == y) return false;
		if (size(x) < size(y)) swap(x,y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	int size(int v) { return -d[root(v)];}
};


int main(void){
	int n;
	cin >> n;
	vector<pair<vector<int>, int>> w[2];
	rep(i, n){
		vector<int> x(2);
		cin >> x[0] >> x[1];
		w[0].push_back(make_pair(x, i));
		swap(x[0], x[1]);
		w[1].push_back(make_pair(x, i));
	}

	vector<vector<mp>> v(n);
	rep(i, 2){
		sort(w[i].begin(), w[i].end());
		rep(j, n-1){
			int c = w[i][j+1].fir[0] - w[i][j].fir[0];
			int p1 = w[i][j+1].sec, p2 = w[i][j].sec;
			v[p1].push_back(mp(c, p2));
			v[p2].push_back(mp(c, p1));
		}
	}
	
	UF t(n);
	lli ans = 0;
	
	pque(mp) q;
	q.push(mp(0, 0));
	while(!q.empty()){
		mp p = q.top(); q.pop();
		if(p.sec == 0 || t.unite(0, p.sec)){
			ans += p.fir;
			rep(i, v[p.sec].size()) if(t.root(0) != t.root(v[p.sec][i].sec)){
				q.push(v[p.sec][i]);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}