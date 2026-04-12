#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,m;

	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}

		int* data = new int[n+m];

		for(int i=0;i<n+m;i++){
			cin >> data[i];
		}
		sort(data,data+(n+m));

		int max = 0;
		int countbuf = 0;

		for(int i=0;i<n+m;i++){
			if(max < data[i] - countbuf){
				max = data[i] - countbuf;
			}
			countbuf = data[i];
		}

		cout << max << endl;
	}
}