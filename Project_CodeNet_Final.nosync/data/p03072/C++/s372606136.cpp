#include<iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	int H[N], i;
	for(i=0; i<N; i++){
		cin >> H[i];
	}
	
	int max=H[0], ans=1;
	for(i=1; i<N; i++){
		if(max<=H[i]){
			max = H[i];
			ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}
