#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define rep(i,N) for(ll i=0; i<N; i++)
const ll mod=1e9+7;

int main(){
	string S;
	cin >> S;
	string ans="No";
	if(S[0] != S[1] || S[0] != S[2] || S[1] != S[2]){
		ans="Yes";
	}
	cout << ans << endl;
	return 0;
}