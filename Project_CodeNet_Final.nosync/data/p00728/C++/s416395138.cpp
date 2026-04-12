#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		int p[100];
		for(int i = 0; i < n; i++){
			cin >> p[i];
		}
		sort(p,p+n);
		int a = 0;
		for(int i = 1; i < n-1; i++){
			a += p[i];
		}
		cout << a/(n-2) << endl;
		cin >> n;
	}
}