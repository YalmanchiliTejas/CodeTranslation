#include<iostream>
using namespace std;
 
int main(){
	char a,b,c;

	cin >> a >> b >> c;

 	if(a == b && b == c) {
    	cout << "No";
    } else if(a != b || a != c || b != c){
    	cout << "Yes";
    }
  
	return 0;		 
}