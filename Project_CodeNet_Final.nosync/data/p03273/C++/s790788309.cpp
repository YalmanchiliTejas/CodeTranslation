// B - Grid Compression
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int main(){
	int H,W; cin>>H>>W;
	vector<string> A(H);
	rp(i,0,H) cin>>A[i];

	vector<string> B;
	rp(h,0,H) rp(w,0,W)
		if(A[h][w] == '#'){ B.push_back(A[h]); break; }

	vector<string> C(B.size());
	rp(w,0,W){
		int h;
		for(h=0; h<B.size(); ++h) if(B[h][w] == '#') break;
		if(h < B.size())
			for(h=0; h<B.size(); ++h) C[h] += B[h][w];
	}

	for(auto x:C) cout<<x<<endl;
}