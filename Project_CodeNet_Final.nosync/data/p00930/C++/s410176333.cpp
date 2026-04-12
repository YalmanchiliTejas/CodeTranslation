#include <iostream>
#include <string>
#include <vector>
#include <set>
#define inf 1000000000

using namespace std;

struct SegTree{
	int size;
	vector<int> seg, delay;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = inf;
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
	
	void update(int i, int val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, int val)
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
		seg[k] = min(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, int val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}

	int query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		int lval = query(a, b, k*2, l, (l+r)/2);
		int rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	int query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

int N, Q;
string s;
SegTree seg(19);
set<int> cand;

int getans(int p)
{
	int ub = p, lb = 0, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(seg.query(mid, p) >= 2) ub = mid;
		else lb = mid;
	}
	return ub;
}

int main(void)
{
	cin >> N >> Q;
	cin >> s;
	s = " " + s;
	
	seg.init();
	int sum = 0;
	for(int i = 1; i <= N; i++){
		if(s[i] == '(') sum++;
		else{
			sum--;
			cand.insert(i);
		}
		seg.update(i, sum);
	}
	
	int p, ans;
	for(int q = 0; q < Q; q++){
		cin >> p;
		if(s[p] == '('){
			s[p] = ')';
			cand.insert(p);
			seg.add(p, N, -2);
			
			while(s[*cand.begin()] == '(') cand.erase(cand.begin());
			ans = *cand.begin();
			s[ans] = '(';
			cand.erase(cand.begin());
			seg.add(ans, N, 2);
		}
		else{
			s[p] = '(';
			if(cand.count(p)) cand.erase(p);
			seg.add(p, N, 2);
			
			ans = getans(p);
			s[ans] = ')';
			cand.insert(ans);
			seg.add(ans, N, -2);
		}
		cout << ans << endl;
	}
	
	return 0;
}

