#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;
int main () { 
	int x;
	cin >> x;
		if(x >= 15){
			x = (x*800) - 200*(x / 15);
				cout << x << endl;
		}else{
			x = x*800;
				cout << x << endl;
		}
} 			
