//ABC107B
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <climits>
#include <cfloat>
#include <string>
#include <numeric>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i=0;i<h;i++){
		cin >> s.at(i);
	}
	vector<bool> t(h), y(w);
	for(int i=0;i<h;i++){
		t.at(i) = false;
	}
	for(int i=0;i<w;i++){
		y.at(i) = false;
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s.at(i).at(j) == '#'){
				t.at(i) = true;
				y.at(j) = true;
			}
		}
	}
	for(int i=0;i<h;i++){
		bool flag = false;
		for(int j=0;j<w;j++){
			if(t.at(i) && y.at(j)){
				cout << s.at(i).at(j);
				flag = true;
			}
		}
		if(flag){
			cout << endl;
		}
	}
	return 0;
}