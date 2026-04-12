#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> vec (H);
	for(int i = 0;i < H;i++){
		cin >> vec.at(i);
	}
	
	int x = 0;
	int y = 0;
	while(x != W-1 || y != H-1){
		if(x == W-1){
			if(vec.at(y+1).at(x) == '.'){
				cout << "Impossible" << endl;
				return 0;
			}
			else{
				y++;
				continue;
			}
		}
		if(y == H-1){
			if(vec.at(y).at(x+1) == '.'){
				cout << "Impossible" << endl;
				return 0;
			}
			else{
				x++;
				continue;
			}
		}
		if(vec.at(y).at(x+1) == '#' && vec.at(y+1).at(x) == '#'){
			cout << "Impossible" << endl;
			return 0;
		}
		if(vec.at(y).at(x+1) == '#'){
			x++;
			if(x == W-1 && y != 0 && vec.at(y-1).at(x) == '#'){
				cout << "Impossible" << endl;
				return 0;
			}
			continue;
		}
		else{
			y++;
			if(y == H-1 && x != 0 && vec.at(y).at(x-1) == '#'){
				cout << "Impossible" << endl;
				return 0;
			}
			continue;
		}
	}
	if(vec.at(y-1).at(x) == '#' && vec.at(y).at(x-1) == '#'){
		cout << "Impossible" << endl;
	}
	else{
		cout << "Possible" << endl;
	}
}