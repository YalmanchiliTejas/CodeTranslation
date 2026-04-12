#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;

using namespace std;
using ll = long long;

template<typename T=int>
T in(){T x; cin >> x; return (x);}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int H=in(),W=in();
	vector<char> B(H*W);
	deque<bool> F(H*W,false);
	REP(i,H){
		REP(j,W){
			B[j+i*W]=in<char>();
		}
	}
	for(int i=0;i<H;i++){
		bool flag = false;
		REP(j,W){
			if(B[i*W+j]=='#'){
				flag = true;
				break;
			}
		}
		if(!flag){
			REP(j,W){
				F[i*W+j] = true;
			}
		}
	}
	for(int j=0;j<W;j++){
		bool flag = false;
		REP(i,H){
			if(B[i*W+j]=='#'){
				flag = true;
				break;
			}
		}
		if(!flag){
			REP(i,H){
				F[i*W+j] = true;
			}
		}
	}

	REP(i,H){
		bool flag=false;
		REP(j,W){
			if(!F[i*W+j]){
				cout << B[i*W+j];
				flag = true;
			}
		}
		if(flag) cout << endl;
	}

	return 0;
}
