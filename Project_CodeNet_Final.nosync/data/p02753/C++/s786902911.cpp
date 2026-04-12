//ABC153C
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <climits>
#include <cfloat>
#include <string>
#include <unordered_map>
using namespace std;



int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.size()-1;i++){
		if(s.at(i) != s.at(i+1)){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}