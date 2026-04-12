#include <iostream>
#include <vector>
using namespace std;

int main(){
	/*input*/
	int h, w;	cin >> h >> w;
	vector<vector<char> >a(h, vector<char>(w));
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> a[i][j];
		}
	}
	/*calcualtion*/
	//row
	vector<bool>whiterow(h, false);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			switch(a.at(i).at(j)){
				case '.':
				whiterow[i] = true;
				break;
				case '#':
				whiterow[i] = false;
				break;
				default:
				break;
			}
			if(!whiterow[i])break;
		}
		if(whiterow[i]){
			whiterow[i] = true;
		}
	}
	//column
	vector<bool>whitecolumn(w, false);
	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			switch(a.at(j).at(i)){
				case '.':
				whitecolumn[i] = true;
				break;
				case '#':
				whitecolumn[i] = false;
				break;
				default:
				break;
			}
			if(!whitecolumn[i])break;
		}
		if(whitecolumn[i]){
			whitecolumn[i] = true;
		}
	}
	
	/*output*/
	for(int i = 0; i < a.size(); i++){
		if(whiterow[i])continue;
		for(int j = 0; j < a.at(i).size(); j++){
			if(whitecolumn[j])continue;
			cout << a[i][j]; 
		}
		cout << endl; 
	}
}
