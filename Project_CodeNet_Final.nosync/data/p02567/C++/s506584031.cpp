#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mInt = modint998244353;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int op(int a,int b){
	return max(a,b);
}
int e(){
	return -1;
}
int t;
bool f(int a){
	return a<t;
}
int main(){
	
	int N,Q;
	cin>>N>>Q;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	
	segtree<int,op,e> seg(A);
	
	rep(i,Q){
		int T;
		cin>>T;
		
		if(T==1){
			int X,V;
			cin>>X>>V;
			seg.set(X-1,V);
		}
		if(T==2){
			int L,R;
			cin>>L>>R;
			cout<<seg.prod(L-1,R)<<endl;
		}
		if(T==3){
			int X,V;
			cin>>X>>V;
			t = V;
			
			cout<<seg.max_right(X-1,f)+1<<endl;
		}
	}
	
    return 0;
}