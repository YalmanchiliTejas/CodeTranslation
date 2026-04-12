#include <iostream>
using namespace std;
int main(){
	while(true){
		int n;
		cin >> n;
		if(n==0){
			break;
		}
		const int MAXN=100;
		int a[MAXN];

		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		int max=a[0], min=a[0], kei=0;
		for(int i=0; i<n; i++){
			if(max < a[i]){
				max=a[i];
			}
			if(min > a[i]){
				min=a[i];
			}
			kei+=a[i];
		}
		int heikin;
		heikin=(kei-max-min)/(n-2);
		cout << heikin << endl;
	}

	return 0;
}