#include <bits/stdc++.h>
using namespace std;

struct StarrySkyTree{
	int seg;
	vector<int> segMin,segAdd;
	StarrySkyTree(int n) : seg(1){
		while(seg < n) seg *= 2;
		segMin.resize(seg * 2 - 1);
		segAdd.resize(seg * 2 - 1);
	}
	inline int getDat(int k){ return segMin[k] + segAdd[k]; }
	void add(int a,int b,int x,int k = 0,int l = 0,int r = -1){
		if(b == -1) b = seg;
		if(r == -1) r = seg;
		if(b <= l || r <= a) return;
		if(a <= l && r <= b){
			segAdd[k] += x;
			return;
		}
		add(a,b,x,k * 2 + 1,l,(l + r) / 2);
		add(a,b,x,k * 2 + 2,(l + r) / 2,r);
		segMin[k] = min(getDat(k * 2 + 1),getDat(k * 2 + 2));
	}
	int find(int x){
		int k = 0,l = 0,r = seg,sum = 0;
		while(r - l > 1){
			sum += segAdd[k];
			if(getDat(k * 2 + 2) + sum < x){
				k = k * 2 + 2;
				l = (l + r) / 2;
			}else{
				k = k * 2 + 1;
				r = (l + r) / 2;
			}
		}
		return l;
	}
};

string s;
set<int> rs;

void flip(int x,StarrySkyTree &seg){
	if(s[x] == '('){
		s[x] = ')';
		seg.add(x + 1,-1,-2);
		rs.insert(x);
	}else{
		s[x] = '(';
		seg.add(x + 1,-1,2);
		rs.erase(x);
	}
}

signed main(){
	int n,q;
	cin >> n >> q >> s;
	StarrySkyTree seg(n + 1);
	for(int i = 0;i < n;i++){
		if(s[i] == '(') seg.add(i + 1,-1,1);
		else{
			seg.add(i + 1,-1,-1);
			rs.insert(i);
		}
	}
	for(int i = 0;i < q;i++){
		int x,ans;
		cin >> x; x--;
		flip(x,seg);
		if(s[x] == ')') ans = *rs.begin();
		else ans = seg.find(2);
		flip(ans,seg);
		cout << ans + 1 << endl;
	}
}
