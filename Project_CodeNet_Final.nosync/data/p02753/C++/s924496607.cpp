#include<bits/stdc++.h>
using namespace std;

template<typename T, typename U> bool chmin(T &a, const U &b) {
	return (a > b ? a = b, true : false);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
	return (a < b ? a = b, true : false);
}

typedef long long ll;

#define writeln(n) cout<<n<<"\n";

typedef pair<int, int> P;
typedef pair<string, int> Psi;

ll numct[210000];
ll k[210000];
ll cnb[210000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin>>s;

	if(s =="AAA"){
		writeln("No");
		return 0;
	}
	if( s =="BBB"){
		writeln("No");
		return 0;
	}
		writeln("Yes");



}
