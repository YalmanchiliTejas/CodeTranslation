#include <iostream>
using namespace std;

int main() {
	string in;
	int a_count = 0, b_count = 0;
	cin >> in;
	for(int i = 0; i < 3; i++){
	    if(in[i] == 'A' ) {
	        a_count++;
	    }else {
	        b_count++;
	    }
	}
	cout << ( a_count == 3 || b_count == 3 ? "No" : "Yes") << "\n";
	
	return 0;
}
