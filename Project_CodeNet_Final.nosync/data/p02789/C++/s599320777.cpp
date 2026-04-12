#include <iostream>
#define llint long long

using namespace std;

llint n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	if(n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}