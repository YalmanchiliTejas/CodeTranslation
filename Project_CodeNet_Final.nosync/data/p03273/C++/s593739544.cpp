#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	auto a = vector<string>(h);
	for(auto& b : a) cin >> b;
	auto r = vector<bool>(h);
	auto c = vector<bool>(w);
	for(auto i = 0; i < h; ++i){
		for(auto j = 0; j < w; ++j){
			if(a[i][j] == '#'){
				r[i] = true;
				c[j] = true;
			}
		}
	}
	for(auto i = 0; i < h; ++i){
		if(!r[i]) continue;
		for(auto j = 0; j < w; ++j){
			if(c[j]) cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}