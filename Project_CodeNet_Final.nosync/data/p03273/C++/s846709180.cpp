#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;



int main() {

	vector<string>p;
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		string x;
		cin >> x;
		p.push_back(x);
	}

	while (1) {
		
		bool f = 0;
		for (int i = 0; i < p.size(); i++) {
			int t = 0;
			for (int j = 0; j < p[i].size(); j++) {
				if (p[i][j] == '#')continue;
				t++;
			}
			if (t == p[i].size()) {
				p.erase(p.begin() + i);
				f = 1;
				i--;
			}
		}

/*
		for (int i = 0; i < p.size(); i++) {
			cout << p[i] << endl;
		}
	*/	
		for (int i = 0; i < p[0].size(); i++) {
			int t = 0;
			for (int j = 0; j < p.size(); j++) {
				if (p[j][i] == '#')continue;
				t++;
			}
			if (t == p.size()) {
				for (int k = 0; k < p.size(); k++) {
					p[k].erase(p[k].begin() + i);
				}
				f = 1;
			}
		}

		

		if (!f)break;




	}
	for (int i = 0; i < p.size(); i++) {
		cout << p[i] << endl;
	}


	return 0;



}