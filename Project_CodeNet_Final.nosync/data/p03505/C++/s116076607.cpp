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
const ll MOD=1e9+7;

int main(){

	ll k, a, b;
	cin >> k >> a >> b;
	b*=-1;
	if(k<=a){
		cout << 1 << endl;
		return 0;
	}
	if(a+b<=0){
		cout << -1 << endl;
	} else {
		cout << (k+b-1)/(a+b)*2+1 << endl;
	}
	
	return 0;
}
