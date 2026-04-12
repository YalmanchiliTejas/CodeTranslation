#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

int main(){
	ll a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	if(x < y){
		swap(x,y);
		swap(a,b);
	}

	cout << min({x*2*c,(x-y)*a+2*y*c,a*x+b*y,x*2*c+y*b,x*a+2*y*c}) << endl;
}
