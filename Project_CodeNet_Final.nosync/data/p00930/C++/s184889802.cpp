#include <bits/stdc++.h>
using namespace std;

int N, Q;
string s;

struct SegmentTree{
	int n;
	vector<int> data;
	vector<int> sum;
	int MAX = 100000000;

	SegmentTree(int nn){
		n = 1;
		while(n < nn) n *= 2;
		data.resize(2 * n - 1, 0);
		sum.resize(2 * n - 1, 0);
	}

	void add(int a, int b, int val){
		add(a, b, val, 0, 0, n);
	}

	void add(int a, int b, int val, int k, int l, int r){
		//cout << k << " " << l << " " << r << endl;
		if(r <= a || b <= l) return;
		//cout << "a";
		if(a <= l && r <= b){
			sum[k] += val;
			return;
		}
		//cout << "b";
		add(a, b, val, k * 2 + 1, l, (l + r) / 2);
		add(a, b, val, k * 2 + 2, (l + r) / 2, r);
		data[k] = min(data[k * 2 + 1] + sum[k * 2 + 1], data[k * 2 + 2] + sum[k * 2 + 2]);
	}

	int query(int a, int b){
		return query(a, b, 0, 0, n);
	}

	int query(int a, int b, int k, int l, int r){
		//cout << k << " " << l << " " << r << endl;
		if(r <= a || b <= l) return MAX;
		if(a <= l && r <= b) return data[k] + sum[k];
		
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr) + sum[k];
	}
};

int main(){
	cin >> N >> Q;
	cin >> s;
	SegmentTree tree(N);
	set<int> pset;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') tree.add(i, s.size(), 1);
		else{
			tree.add(i, s.size(), -1);
			pset.insert(i);
		}
		/*
		for(int i = 0; i < s.size(); i++){
			cout << tree.query(i, i + 1) << " " ;
		}

		cout << endl;
		*/
	}

	for(int i = 0; i < Q; i++){
		int idx;
		cin >> idx;
		idx--;
		if(s[idx] == '('){
			s[idx] = ')';
			pset.insert(idx);
			tree.add(idx, N, -2);
			int vv = *begin(pset);
			s[vv] = '(';
			pset.erase(vv);
			tree.add(vv, N, 2);
			cout << (vv + 1) << endl;

		}else{
			pset.erase(idx);
			s[idx] = '(';
			tree.add(idx, N, 2);
			int l = -1;
			int r = N - 1;
			while(r - l > 1){
				int m = (l + r) / 2;
				if(tree.query(m, N) >= 2){
					r = m;
				}else{
					l = m;	
				}
			}
			while(s[r] != '(') r++;
			tree.add(r, N, -2);
			s[r] = ')';
			pset.insert(r);
			cout << (r + 1) << endl;
		}
	}
}