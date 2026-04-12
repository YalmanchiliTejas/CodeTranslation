#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
	int x, y, z;
	cin >> x >> y >> z;

	int ans = (x - z) / (y + z);
	cout << ans << endl;


    return 0;
}
