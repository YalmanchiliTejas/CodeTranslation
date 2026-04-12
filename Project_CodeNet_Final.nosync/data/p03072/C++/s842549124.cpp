#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef set<int> S;
#define rep(i, n) for(int i=0; i<n; i++)
const ll MOD=1e9+7;

int main(){

	int n, h[20], ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	int now = h[0];
	for(int i = 0; i < n; i++){
		if(now <= h[i]){
			ans++;
			now = h[i];
		}
	}
	cout << ans << endl;

	return 0;
}