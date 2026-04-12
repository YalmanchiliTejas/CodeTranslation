#include <iostream>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <string>
#include<algorithm>


using namespace std;


int main(){
	string s;
	cin >> s;
	if(s.find("AC") != string::npos){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

    return 0;
}