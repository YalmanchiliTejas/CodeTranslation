#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int x, y, z; cin >> x >> y >> z;
	x -= z;
	printf("%d\n", x / (y + z));
	return 0;
}