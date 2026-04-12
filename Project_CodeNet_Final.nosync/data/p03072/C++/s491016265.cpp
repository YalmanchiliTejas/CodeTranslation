#include <iostream>
using namespace std;

int main(){
	/*input*/
	int n; cin >> n;
	int* h = new int[n]; 
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	/*calculation*/
	int o = 0;			//旅館の数
	int heighest = 0;	//iの時点で最も高い山 
	for(int i = 0; i < n; i++){
		if(h[i] >= heighest){
			heighest = h[i];
			o++;
		}
	}

	/*output*/
	cout << o << endl;
	delete[] h;
}
