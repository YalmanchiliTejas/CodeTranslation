#include <iostream>
#include <cstdio>
using namespace std;

int main (){
  	int a,b,c;
  	cin >> a >>b >>c;
    int t = b*10+c;
  	if(t%4==0){
    	cout << "YES" << endl;
    }
  	else {
    	cout << "NO"  << endl; 
    }
	return 0;
}