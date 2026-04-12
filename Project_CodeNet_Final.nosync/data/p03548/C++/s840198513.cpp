#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(v) v.begin(),v.end()
#define PI acos(-1)
#define EPS 1e-15



int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if(abs(x - x/(y+z)*(y+z)) >= z){
		cout << x/(y+z) << endl;
	}else
		cout << x/(y+z) -1 << endl;
	return 0;
}




