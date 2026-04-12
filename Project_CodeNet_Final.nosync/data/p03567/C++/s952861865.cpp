#include <iostream>
using namespace std;

int main(void){
	string a;
	cin >> a;
	for(int i=0; i<=5; i++){
		if(a[i] == 'A' && a[i+1]=='C'){
			cout << "Yes" << endl;
			return 0;
		}
		
	}

			cout << "No" << endl;
	return 0;
}