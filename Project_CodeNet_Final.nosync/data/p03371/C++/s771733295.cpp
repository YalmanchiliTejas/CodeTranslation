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

	ll A=in<ll>(),B=in<ll>(),C=in<ll>(),X=in<ll>(),Y=in<ll>();
	ll minXY=min(X,Y),maxXY=max(X,Y);
	ll cost = 0;
	if((A+B)>2*C){
		cost += 2*C*minXY;
		if(minXY==X){
			if(B>2*C){
				cost += 2*C*(Y-X);
			}
			else{
				cost += B*(Y-X);
			}
		}
		else{
			if(A>2*C){
				cost += 2*C*(X-Y);
			}
			else{
				cost += A*(X-Y);
			}
		}
	}
	else{
		cost += A*X+B*Y;
	}

	cout << cost << endl;
	return 0;
}
