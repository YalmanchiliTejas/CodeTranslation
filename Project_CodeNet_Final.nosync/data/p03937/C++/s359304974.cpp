#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int h, w;
	cin >> h >> w;
	int ww = 0;
	for(int i = 0; i < h; i++){
		bool ny = true;
		bool re = false;
		for(int j = 0; j < w; j++){
			char aa;
			cin >> aa;
			if(ny && (aa=='#')){
				if(j == ww)ny = false;
				else{
					cout << "Impossible" << endl;
					return 0;
				}
				re = true;
			}
			else if(!ny&&(aa=='#')){
				if(j != ww+1){
					cout << "Impossible" << endl;
					return 0;
				}
				else ww++;
				re = true;
			}
		}
		if(!re){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
    return 0;
}