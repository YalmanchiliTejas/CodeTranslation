
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdint>
#define rep(ident, start, end) for(int ident=start;ident<end;ident++)

using namespace std;

int main(void){
	int H, W;
	cin >> H >> W;
	string l;
	vector<string> v;
	rep(i, 0, H){
		cin >> l;
		v.push_back(l);
	}
	bool process = true;
	while (process){
		process = false;
		rep (i, 0, H){
			if (v[i].find("#") == string::npos){
				v.erase(v.begin()+i);
				process = true;
				H--;
				break;
			}
		}
		if(process == false)
		rep(i, 0, W){
			rep(j, 0, H){
				if (v[j][i] == '#')break;
				if (j == H - 1){
					rep(k, 0, H)v[k].erase(v[k].begin() + i);
					W--;
					process = true;
					break;
				}
			}
			if (process == true)break;
		}
	}

	rep(i, 0, H)cout << v[i] <<endl;
	return 0;
}