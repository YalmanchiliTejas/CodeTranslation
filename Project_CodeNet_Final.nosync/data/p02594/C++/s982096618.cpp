//-----------------------
// author : xyqkoala
// time : 2020-08-03
//-----------------------

#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long LL;
const int MOD = 1e9+7;

void solve();


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


void solve(){
	int n;
	cin>>n;
	cout<<(n>=30?"Yes":"No")<<endl;
}
