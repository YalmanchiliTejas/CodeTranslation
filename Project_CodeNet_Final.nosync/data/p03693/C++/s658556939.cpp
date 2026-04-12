#include <iostream>
using namespace std;
 //Compiler version g++ 4.9

 int main()
 {
 	int r, g, b;
 	int num;
 	cin >> r >> g >> b;
 	num = r * 100 + g * 10 + b;
 	if(num % 4 == 0){
 		cout << "YES" << endl;
 	}else{
 		cout << "NO" << endl;
 	} 
 }