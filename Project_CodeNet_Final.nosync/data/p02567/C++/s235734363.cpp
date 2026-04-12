#include <bits/stdc++.h>
using namespace std;
int seg[524288]; 
void update(int k, int a){
	k += 262143; 
	seg[k] = a; 
	while(k > 0){
		k = (k - 1) / 2; 
		seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]); 
	}
}
long long query(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return 0; 
	if(a <= l && b >= r) return seg[k]; 
	else{
		long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2); 
		long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r); 
		return max(vl, vr); 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	int N, Q; cin >> N >> Q; 
	for(int i = 0; i < N; i++){
		int a; cin >> a; update(i, a); 
	}
	update(N, 1145141919); 
	while(Q--){
		int T; cin >> T; 
		if(T == 1){
			int X, V; cin >> X >> V; 
			X--; update(X, V); 
		}else if(T == 2){
			int L, R; cin >> L >> R; L--; 
			cout << query(L, R, 0, 0, 262144) << "\n"; 
		}else if(T == 3){
			int X, V; cin >> X >> V; X--; 
			int ng = X; int ok = N+1; 
			while(ok - ng > 1){
				int mid = (ok + ng) / 2; 
				if(query(X, mid, 0, 0, 262144) >= V) ok = mid; 
				else ng = mid; 
			}
			cout << ok << "\n"; 
		}
	}
}