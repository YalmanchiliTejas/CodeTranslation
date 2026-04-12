#include <iostream>
using namespace std;

int heights[20];

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> heights[i];
	}

	int max = 0;
	int count = 0;

	for(int i = 0; i < n; ++i){
		if(heights[i] >= max){
			++count;
			max = heights[i];
		}else{
			//nothing
		}
	}

	cout << count << endl;

	return 0;
}