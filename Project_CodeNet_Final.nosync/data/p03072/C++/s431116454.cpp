#include <iostream>
using namespace std;

int N[20];




int main(){
	int n;
	int count = 0;
	int M = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> N[i];

	for (int i = 0; i < n; i++){
		if (M <= N[i]){
			M = N[i];
			count++;
		}
	}
	cout << count << endl;
}