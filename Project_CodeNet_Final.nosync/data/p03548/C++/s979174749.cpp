#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int x,y,z;
	cin >> x >> y >> z;
	x -= z;
	cout << x/(y+z) << endl;
	return 0;
}