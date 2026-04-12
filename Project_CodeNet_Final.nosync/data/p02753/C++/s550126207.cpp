#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

int main(){
	string t;
	cin >> t;

	
	char first = t[0];
	char second = t[1];
	char third = t[2];
	
	if (first == second && second == third){
		cout << "No";
		return 0;
	}
	else cout << "Yes";	
	
	
	return 0;
}
