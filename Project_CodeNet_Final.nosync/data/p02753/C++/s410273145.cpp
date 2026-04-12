#include<iostream>
#include <algorithm>
#include<string.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long int llint;
using namespace std;


int main() {
	string s;// a,b;
	cin >> s; 
    //a = "AAA";
    //b = "BBB";
    if(s=="AAA" || s=="BBB"){
      	cout << "No";
    }else{
    	cout << "Yes";
    }   
	return 0;
}