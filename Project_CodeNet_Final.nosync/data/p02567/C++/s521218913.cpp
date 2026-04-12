//vectorはintじゃないとCEする
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using namespace atcoder;

int op(int a,int b){return max(a,b);}

int e(){return -1;}

int target;

bool f(int v){return v<target;}


int main() {
  long long N,Q;
	cin>>N>>Q;
	vector<int> a(N);
	rep(i,N)cin>>a[i];
	segtree<int,op,e> seg(a);
	rep(i,Q){
		int T;
	  cin>>T;
		if(T==1){
			long long X,V;
			cin>>X>>V;
			X--;
			seg.set(X,V);
		}else if(T==2){
			long long X,V;
			cin>>X>>V;
			X--;
			cout<<seg.prod(X,V)<<"\n";
		}else{
			long long X;
		  cin>>X>>target;
			X--;
			cout<<seg.max_right<f>(X)+1<<"\n";
		}
	}
	return 0;
}