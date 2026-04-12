#include <iostream>
using namespace std;

int main(){
	/*input*/
	int x;	cin >> x;
	/*output*/
	switch(x){
		case 3:
		case 5:
		case 7:
		cout << "YES" << endl;	
		break;

		default:
		cout << "NO" << endl;
		break;
	}
}
