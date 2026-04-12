#include <iostream>

#include <vector>

using namespace std;

int main(){

	int n;
	vector <int> a;

	cin >> n;

	int t;
	for(int i=0; i < n; ++i){
		cin >> t;
		a.push_back(t);
	}


	if( n % 2 == 0){
		for(int i = 0; i < n/2; ++i)
			cout << a[n - 1 - 2*i] << " ";
		for(int i = 0; i < n/2; ++i)
			cout << a[2*i] << " ";
		cout << endl;
	}else{
		for(int i = 0; i < n/2; ++i)
			cout << a[n - 1 - 2*i] << " ";
		cout << a[0]  << " ";
		for(int i = 0; i < n/2; ++i)
			cout << a[2*i + 1] << " ";
		cout << endl;
	}

	return 0;
}