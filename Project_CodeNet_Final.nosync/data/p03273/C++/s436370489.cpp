#include <bits/stdc++.h>
using namespace std;
int h;
int w;
int main(){
	bool flag = false;
	cin>>h>>w;
	vector<vector<char>> arr(h, vector<char>(w));
	vector<vector<char>> test(h, vector<char>(w, 'b'));
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin>>arr.at(i).at(j);
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			flag = false;
			if(arr.at(i).at(j) != '.'){
				flag = true;
				break;
			}
		}
		if(!flag){
			for(int k = 0; k < w; k++){
				test.at(i).at(k) = 'w';
			}
		}
	}
	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			flag = false;
			if(arr.at(j).at(i) != '.'){
				flag = true;
				break;
			}
		}
		if(!flag){
			for(int k = 0; k < h; k++){
				test.at(k).at(i) = 'w';
			}
		}
	}
	int count = 0;
	for(int i = 0; i < h; i++){
		count = 0;
		for(int j = 0; j < w; j++){
			flag = true;
			if(test.at(i).at(j) == 'w'){
				flag = false;
				continue;
			}
			count++;
			cout<<arr.at(i).at(j);
		}
		if(count > 0)cout<<endl;
	}
	if(!flag)cout<<endl;
}