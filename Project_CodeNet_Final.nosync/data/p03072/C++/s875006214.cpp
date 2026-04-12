#include <iostream>
using namespace std;

int n;
int h[101];

int main(){
	cin >> n;
	
	for(int i=0; i<n; ++i){
		cin >> h[i];
	}
	
	int max = h[0];
	int time =1;
	for(int i=1; i<n; ++i){
		if(h[i]>=max){
			++time;
			max = h[i];
		}
	}
	
	cout << time;
	
	return 0;

}