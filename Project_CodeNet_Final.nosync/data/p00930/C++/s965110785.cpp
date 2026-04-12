#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int n, q, x, ans ;
string str;
set<int> l;
set<int> r;
#define INF (1<<29)

int seg[1<<20];
int all[1<<20];

void add(int l, int r, int val, int bottom = 0, int top = 1 << 19, int p = 1){
	if(r <= bottom || top <= l)return;
	if(l <= bottom && top <= r){
		all[p] += val;
		return;
	}
	int mid = (top + bottom) / 2;
	add(l, r, val, bottom, mid, p*2);
	add(l, r, val, mid, top, p*2+1);
	seg[p] = min(seg[p*2] + all[p*2], seg[p*2+1] + all[p*2+1]);
}

int minval(int l, int r, int bottom = 0, int top = 1 << 19, int p = 1){
	if(r <= bottom || top <= l)return INF;
	if(l <= bottom && top <= r)return seg[p] + all[p];
	int mid = (top + bottom) / 2;
	return all[p] + min(minval(l, r, bottom, mid, p * 2),
											minval(l, r, mid, top, p * 2 + 1));
}



int solve(int x){
	int l = 0, rr = n;
	while(rr - l > 1){
		int mid = (l + rr) / 2;
		int tmp = *r.lower_bound(mid);
		if(minval(mid, n) < 2)l = mid;
		else rr = mid;
	}
	return rr;
}

int main(){
	cin >> n >> q;
	cin >> str;
	for(int i = 0;i < str.size();i++){
		if(str[i] == '('){
			add(i,n, 1);
			l.insert(i);
		}
		if(str[i] == ')'){
			add(i,n, -1);
			r.insert(i);
		}
	}
	while(q--){
		cin >> x;x--;
		if(str[x] == '('){
			str[x] = ')';
			l.erase(x);
			r.insert(x);
			add(x,n,-2);
			ans = *r.begin();
			r.erase(ans);
			l.insert(ans);
			add(ans, n, 2);
			str[ans] = '(';
		}
		else{
			l.insert(x);
			r.erase(x);
			str[x] = '(';
			add(x, n, 2);
			ans = solve(x);
			l.erase(ans);
			r.insert(ans);
			add(ans,n, -2);
			str[ans] = ')';
		}
		ans++;
		cout << ans << endl;

	}
	return 0;
}