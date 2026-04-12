#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int h,w;
	string s;
	cin >> h >> w;
	int count = 0;

	for(int i = 0; i < h; i++){
		cin >> s;
		for(int j = 0; j < w; j++){
			if(s[j] == '#'){
				count++;
			}
		}
	}


	if(count == h+w-1){
		cout << "Possible" << endl;

	}else{
		cout << "Impossible" << endl;
	}

	return 0;
}