#include <iostream>
#include <vector>

using namespace std;

int main(){
	int h, w, i, j, k;//horizontal, vertical
	cin >> h >> w;
    vector<vector<char>> a;
    for(i=0;i<h;i++){
    	vector<char> sub_a(w);
		a.push_back(sub_a);
		for(j=0;j<w;j++){
			cin >> a[i][j];
		}
    }

    bool whiteOnly;

    //horizontal
    for(i=0;i<h;i++){
		whiteOnly = true;
		for(j=0;j<w;j++){
			if(a[i][j]=='#'){
				whiteOnly = false;
				break;
			}
		}
		if(whiteOnly){
			a.erase(a.begin()+i);
			h = h-1;
			i--;
		}
    }

    //vertical
    for(j=0;j<w;j++){
		whiteOnly = true;
		for(i=0;i<h;i++){
			if(a[i][j]=='#'){
				whiteOnly = false;
				break;
			}
		}
		if(whiteOnly){
			for(k=0;k<h;k++){
				a[k].erase(a[k].begin()+j);
			}
			w = w-1;
			j--;
		}
    }

    for(i=0;i<(int)a.size();i++){
		for(j=0;j<(int)a[i].size();j++){
			cout << a[i][j];
			if(j+1==(int)a[i].size()){
				cout << endl;
			}
		}
    }

	return 0;
}

