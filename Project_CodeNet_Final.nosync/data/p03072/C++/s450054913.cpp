#include <iostream>
#include <algorithm>

using namespace std;

int main(){
		int n;
		cin >> n;
		int mountains[n];
		for(int i=0; i<n; i++){
				cin >> mountains[i];
		}

		int cnt =1;
		int max = mountains[0];
		for(int i=1; i<n; i++){
				if(mountains[i] >= max){
						cnt++;
						max = mountains[i];
				}
		}
		cout << cnt << endl;
}