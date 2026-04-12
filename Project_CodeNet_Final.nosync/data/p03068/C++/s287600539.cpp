#include<iostream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<math.h>
#include"boost/algorithm/string.hpp"

using namespace std;


int main(){
	/*Q2*/
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	int k;
	cin >> k;
	k--;

	char c = s[k];

	for (int i = 0; i < s.size(); ++i){
		if (s[i]!= c){
			s[i] = '*';
		}
	}

	cout << s << endl;
	/*Q1*/
	/*
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b){
		if (a < c && c < b){
			cout << "Yes" << endl;
			return 0;
		}
	}

	else{
		if (b < c && c < a){
			cout << "Yes" << endl;
			return 0;
		}


	}

	cout << "No" << endl;
	*/

	return 0;
}