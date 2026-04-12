#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

#define sz(x) (int)(x.size())

#define rep(i, a, b) for(int i=a;i<b;++i)
typedef long long ll;

int const N = 4e5 + 41;
int const INF = 1e9 + 41;

int p[N], x[N], y[N], invP[N], pos[N];
int n, color[N], cnt;
ll ans;

int getOther(int i){
	if(i >= n) return i - n;
	else return i + n;
}

int getVal(int i){
	if(i < n) return x[i];
	else return y[i-n];
}

bool comp(int i, int j){
	return getVal(i) < getVal(j);
}

multiset<int> q[2];

int getMin(multiset<int> &q){
	if(sz(q) == 0) return INF;
	int res = (*q.begin());
	return res;
}

int getMax(multiset<int> &q){
	if(sz(q) == 0) return -INF;
	auto res = (q.end());
	--res;
	return (*res);
}

bool tryMoveLp(int &lp){
	if(pos[invP[p[lp]]] < lp) return false;
	q[0].erase(q[0].find(getVal(p[lp])));
	q[0].insert(getVal(invP[p[lp]]));
	q[1].insert(getVal(p[lp]));
	q[1].erase(q[1].find(getVal(invP[p[lp]])));
	++lp;
	return true;
}

bool tryMoveRp(int &rp, int &cnt){
	if(rp == n * 2) return false;
	if(pos[p[rp]] < pos[invP[p[rp]]]){
		q[0].insert(getVal(p[rp]));
		q[1].insert(getVal(invP[p[rp]]));
		++cnt;
	}
	++rp;
	return true;
}

void solve(){
	ans = INF * 1LL * INF;
	cin >> n;
	rep(i, 0, n) cin >> x[i] >> y[i], p[i] = i, p[i+n] = i + n, invP[i] = i + n, invP[i + n] = i;
	sort(p, p + n * 2, comp);
	rep(i, 0, n * 2) pos[p[i]] = i;
	int lp = 0;
	int rp = 0;
	int cnt = 0;
	while(lp < n * 2){
		if(cnt == n){
			ans = min(ans, (getMax(q[0]) - getMin(q[0])) * 1LL * (getMax(q[1]) - getMin(q[1])));
			if(!tryMoveLp(lp)) break;
		}else{
			if(!tryMoveRp(rp, cnt)) break;
		}
	}
	cout << ans << endl;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();


	return 0;
}