#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0, top = 0;
	for(auto i = 0; i < n; ++i){
		int h;
		cin >> h;
		if(h >= top){
			++ans;
			top = h;
		}
	}
	cout << ans << endl;
	return 0;
}