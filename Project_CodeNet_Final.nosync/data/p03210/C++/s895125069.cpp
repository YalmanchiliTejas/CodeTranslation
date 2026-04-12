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

	int X=in();

	cout << ((X==7 || X==5 || X==3)?"YES":"NO") << endl;

	return 0;
}