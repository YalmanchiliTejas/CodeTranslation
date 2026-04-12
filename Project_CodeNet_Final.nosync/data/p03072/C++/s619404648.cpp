#include<iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int ans = 0;
	int height = 0;
	for(int i=0;i<N;++i){
		int dh;
		cin>>dh;
		if(dh >= height){
			height = dh;
			++ans;
		}	
	}
	cout << ans << endl;
	return 0;
}
