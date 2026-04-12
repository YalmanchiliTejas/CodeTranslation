// B - Grid Compression
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	int H,W; cin>>H>>W;
	vector<string> A(H);
	rep(i, H) cin>>A[i];

	vector<bool> row(H, false), col(W, false);
	rep(h, H) rep(w, W)
		if(A[h][w] == '#') row[h] = col[w] = true;

	rep(h, H)
		if(row[h]){
			rep(w, W) if(col[w]) cout<<A[h][w];
			puts("");
		}
}