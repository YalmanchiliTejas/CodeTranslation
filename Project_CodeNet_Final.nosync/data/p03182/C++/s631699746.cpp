#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <int, ll> pil;
#define x first
#define y second
#define mp make_pair

struct node{
	ll mval, upd;
};

node t[(1 << 19) + 5];
vector <pil> seg[200005];
int n, m;

void update(int root, int l, int r, int s, int e, ll val){
	if(l > r || l > e || r < s)
		return;
	if(l >= s && r <= e){
		t[root].mval += val;
		t[root].upd += val;
		return;
	}
	int mid = (l + r) / 2;
	update(root * 2, l, mid, s, e, val);
	update(root * 2 + 1, mid + 1, r, s, e, val);
	t[root].mval = max(t[root * 2].mval, t[root * 2 + 1].mval) + t[root].upd;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
for(int i = 1 ; i <= m ; ++i){
	int l, r;
	ll w;
	cin >> l >> r >> w;
	seg[r].push_back(mp(l, w));
}
for(int i = 1 ; i <= n ; ++i){
	update(1, 1, n, i, i, t[1].mval);
	for(vector <pil>::iterator j = seg[i].begin() ; j != seg[i].end() ; ++j){
		pil o = *j;
		update(1, 1, n, o.x, i, o.y);
	}
}
cout << max(0LL, t[1].mval) << endl;

return 0;
}

