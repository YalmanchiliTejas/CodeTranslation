// B - Grid Compression
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int main(){
	int H,W; cin>>H>>W;
	vector<string> A(H);
	rp(i, 0, H) cin>>A[i];

	vector<bool> row(H, false);
	rp(h, 0, H) rp(w, 0, W)
		if(A[h][w] == '#'){ row[h] = true; break; }

	vector<bool> col(W, false);
	rp(w, 0, W) rp(h, 0, H)
		if(A[h][w] == '#'){ col[w] = true; break; }

	rp(h, 0, H){
		int f = false;
		rp(w, 0, W) if(row[h] && col[w]){ cout<<A[h][w]; f = true; }
		if(f) puts("");
	}
}