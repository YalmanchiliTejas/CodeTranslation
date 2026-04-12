#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)
// #define NMAX 1000000000
int H,W;
vector<string> A;

void solve(){

	vector<string> B;
	rp(h,0,H){
		rp(w,0,W){
			if(A[h][w] == '#'){
				B.push_back(A[h]);
				break;
			}
		}
	}

	// for(auto x:B) cout<<x<<endl;///

	vector<string> C(B.size());

	int wc = 0;
	rp(w,0,W){
		int h;
		for(h=0; h<B.size(); ++h){
			if(B[h][w] == '#'){
				break;
			}
		}

		// cout<<h<<" "<<B.size()<<"\n";///
		if(h < B.size()){
			for(h=0; h<B.size(); ++h){
				C[h] += B[h][w];
			}
		}

	}

	for(auto x:C) cout<<x<<endl;

}

int main(){
	cin>>H>>W;
	A.resize(H);
	rp(i,0,H) cin>>A[i];
	solve();
}
