#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b;
    cin >> r >> g >> b;
    int ans = r*100 + g*10 + b;
	if(ans%4==0) cout << "YES\n";
	else cout << "NO\n";    
    
	return 0;
}