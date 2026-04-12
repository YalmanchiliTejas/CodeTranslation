#include <bits/stdc++.h>
using namespace std;
#define ote(x) cout<<(x)<<endl
#define rp(i,s,e) for(int i=(s);i<(e);++i)
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

int N;
int a,b,c,d,e;
string S, T;

// auto solve(){
// 	auto ans = 0;
// 	return ans;
// }

int main(){
	cin>>S;
	auto ans = "Yes";
	if(S[0]==S[1] && S[1]==S[2]) ans = "No";
	cout<< ans <<endl;
	// cout<< solve() <<endl;
	// printf("%f\n",solve());
}
