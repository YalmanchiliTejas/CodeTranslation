#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

int32_t main(){
	string s;
	cin>>s;
	set<int> se;
	for(auto x: s){
		se.insert(x);
	}
	if(se.size()>1){
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}
}
