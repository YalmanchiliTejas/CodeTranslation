#include <bits/stdc++.h>
using namespace std;
int M, N, N_; 
long long seg[524300], lazy[524300]; 
long long D[200010], S[200010]; 
vector<pair<int, long long>> fi[200010], se[200010]; 
void init(int N_){
	N = 1; 
	while(N < N_) N *= 2; 
	for(int i = 0; i < N * 2 - 1; i++){
		seg[i] = 0; lazy[i] = 0;  
	}
}
void update(int k){
	if(lazy[k] == 0) return; 
	seg[k] += lazy[k]; 
	if(k * 2 + 2 < N * 2 - 1){
		lazy[k * 2 + 1] += lazy[k]; 
		lazy[k * 2 + 2] += lazy[k]; 
	}
	lazy[k] = 0; 
}
void add(int a, int b, int k, int l, int r, long long x){
	update(k); 	
	if(b <= l || r <= a) return; 
	if(a <= l && r <= b){
		lazy[k] += x; 
		update(k); 
	}else{
		add(a, b, k * 2 + 1, l, (l+r)/2, x);
		add(a, b, k * 2 + 2, (l+r)/2, r, x);
		seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
	}
}
long long query(int a, int b, int k, int l, int r){
	if(b <= l || r <= a) return 0; 
	update(k); 
	if(a <= l && r <= b) return seg[k];
	long long vl = query(a, b, k * 2 + 1, l, (l+r)/2);
	long long vr = query(a, b, k * 2 + 2, (l+r)/2, r);
	return max(vl, vr); 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N_ >> M;
	N_ ++; init(N_);
	for(int i = 0; i < M; i++){
		int l, r; long long a; 
		cin >> l >> r >> a; 
		fi[r].emplace_back(l, a); 
		se[l].emplace_back(r, a); 
		D[l] += a; D[r+1] -= a; 
	}
	for(int i = 1; i <= N_; i++){
		S[i] = S[i-1] + D[i]; 
	}
	for(int i = 1; i <= N_; i++){
		for(auto p : fi[i-1]){
			add(p.first, i, 0, 0, N, p.second); 
		}
		for(auto p : se[i]){
			add(i, p.first + 1, 0, 0, N, -p.second); 
		}
		long long mx = query(0, i, 0, 0, N); 
		add(i, i+1, 0, 0, N, S[i] + mx); 
	}
	for(auto p : fi[N_]){
		add(p.first, N_+1, 0, 0, N, p.second); 
	}
	cout << query(0, N, 0, 0, N) << "\n"; 
}