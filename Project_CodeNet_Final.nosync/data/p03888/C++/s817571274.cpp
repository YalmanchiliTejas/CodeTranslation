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

	double r1, r2;
	cin >> r1 >> r2;
	cout << setprecision(10);
	cout << r1*r2/(r1+r2) << endl;

	return 0;
}
