#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	string S;
	cin>>S;
	string ans = "No";
	rep(i,S.size()-1){
		if(S.substr(i,2)=="AC")ans="Yes";
	}
	cout<<ans<<endl;
}