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

	int n, k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;
	for(int i=0; i<n; i++){
		if(s[k-1]==s[i]){
			cout << s[i];
		} else {
			cout << "*";
		}
	}
	cout << endl;

	return 0;
}