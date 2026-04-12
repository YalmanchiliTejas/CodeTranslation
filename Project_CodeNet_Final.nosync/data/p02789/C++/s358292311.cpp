#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pri;
const int INF = 1e9 + 7;
const ll LINF = 1LL<<61;

int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(n <= m){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}