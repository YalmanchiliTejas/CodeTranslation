#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int m;
	cin >> m;
	while(m--){
		int a, y, n, answer = 0;
		cin >> a >> y >> n;
		while(n--){
			int mode, f;
			double rate;
			cin >> mode >> rate >> f;
			if(mode){
				int v = a;
				for(int i = 0; i < y; ++i){
					v = static_cast<int>(v * rate) + v - f;
				}
				answer = max(v, answer);
			}else{
				int v = a, p = 0;
				for(int i = 0; i < y; ++i){
					p += static_cast<int>(v * rate);
					v -= f;
				}
				answer = max(v + p, answer);
			}
		}
		cout << answer << endl;
	}
	return 0;
}