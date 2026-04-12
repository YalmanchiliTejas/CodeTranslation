#include <iostream>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<int, int> P;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

struct SegTree{
	int size;
	vector<llint> seg, delay;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = -inf;
			delay[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			seg[k] += delay[k];
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = max(seg[i*2], seg[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = max(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}

	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, m;
llint l[200005], r[200005], a[200005];
vector<P> vec[200005];
llint dp[200005];
SegTree seg(18);
BIT bit(200005);


int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> a[i];
	
	for(int i = 1; i <= m; i++){
		vec[l[i]].push_back(make_pair(i, 0));
		vec[r[i]+1].push_back(make_pair(i, 1));
	}
	
	bit.init();
	seg.init(); seg.add(0, n, inf);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < vec[i].size(); j++){
			int id = vec[i][j].first;
			if(vec[i][j].second == 0){
				bit.add(l[id], a[id]);
				seg.add(l[id], n, -a[id]);
			}
			else{
				bit.add(l[id], -a[id]);
				seg.add(l[id], n, a[id]);
			}
		}
		dp[i] = seg.query(0, i-1) + bit.query(i);
		seg.add(i, i, dp[i]);
	}
	
	llint ans = 0;
	for(int i = 0; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
	
	return 0;
	
}