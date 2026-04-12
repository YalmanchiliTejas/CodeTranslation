#include<bits/stdc++.h>
using namespace std;

template<typename T, typename U> bool chmin(T &a, const U &b) {
	return (a > b ? a = b, true : false);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
	return (a < b ? a = b, true : false);
}
const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n";

typedef pair<int, int> P;
typedef pair<string, int> Psi;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m;cin>>n>>m;
	
	if(n ==m){
		writeln("Yes");
	}else {
		writeln("No");
	}
}


