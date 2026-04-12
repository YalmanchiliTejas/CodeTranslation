#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;

typedef long long int ll;

void solve(){
	string str;
	cin >> str;
	if(str == "AAA" || str == "BBB"){
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;
}

int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	//cin >> T;
	T= 1;
	while(T--){
		solve();
	}
	return 0;
}


