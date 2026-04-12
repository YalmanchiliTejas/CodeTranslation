#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

long long int INF = 1e18;
int const TREE_SIZE = 1 << 21;
long long int seg_tree[TREE_SIZE] = {};
long long int c_diff[TREE_SIZE] = {}; // 子との差

// [a, b) の最小値を求める
// find(a, b + 1, 1, 0, 0, TREE_SIZE / 2)
long long int find(int a, int b, int index, long long int diff, int l, int r){
	seg_tree[index] += diff;
	c_diff[index] += diff;
	
	if(r <= a || b <= l){
		return INF;
	}
	if(a <= l && r <= b){
		return seg_tree[index];
	}
	
	long long int ret = INF;
	ret = min(ret, find(a, b, index * 2, c_diff[index], l, (l + r) / 2));
	ret = min(ret, find(a, b, index * 2 + 1, c_diff[index], (l + r) / 2, r));
	c_diff[index] = 0;
	return ret;
}

// [a, b) に num を足す
// add(a, b + 1, 1, num, 0, 0, TREE_SIZE / 2);
long long int add(int a, int b, int index, long long int num, long long int diff, int l, int r){
	seg_tree[index] += diff;
	c_diff[index] += diff;
	
	if(r <= a || b <= l){
		return seg_tree[index];
	}
	if(a <= l && r <= b){
		seg_tree[index] += num;
		c_diff[index] += num;
		return seg_tree[index];
	}
	
	long long int ret = INF;
	ret = min(ret, add(a, b, index * 2, num, c_diff[index], l, (l + r) / 2));
	ret = min(ret, add(a, b, index * 2 + 1, num, c_diff[index], (l + r) / 2, r));
	c_diff[index] = 0;
	return seg_tree[index] = ret;
}

int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<pair<P,P>, vector<pair<P,P>>, greater<pair<P,P>>> quel, quer;

    rep(i,m){
        int l, r, a;
        cin >> l >> r >> a;
        pair<P,P> p;
        p.first.first = l;
        p.first.second = r;
        p.second.first = a;
        p.second.second = 1;
        quel.push(p);
        p.first.first = r;
        p.first.second = l;
        p.second.second = -1;
        quer.push(p);
    }

    ll now = 0;
    srep(i,1,n+1){
        while(!quel.empty() && quel.top().first.first <= i){
            now += quel.top().second.first;
            quel.pop();
        }
        ll tmp = find(0,i,1,0,0,TREE_SIZE/2);
        add(i,i+1,1,tmp,0,0,TREE_SIZE/2);
        while(!quer.empty() && quer.top().first.first <= i){
            now -= quer.top().second.first;
            int l = quer.top().first.second;
            int r = quer.top().first.first;
            ll a = quer.top().second.first;
            add(l,r+1,1,-a,0,0,TREE_SIZE/2);
            quer.pop();
        }
    }

    ll ans = find(0,n+1,1,0,0,TREE_SIZE/2);
    cout << -ans << endl;
	
	return 0;
}

