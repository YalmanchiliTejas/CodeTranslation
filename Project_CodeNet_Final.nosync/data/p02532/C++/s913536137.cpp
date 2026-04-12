#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <functional>
#include <stack>
#define PI 3.1415926535

using namespace std;

char c;
string s;
stack<int> d[100];
int n, t;

int main(){
	cin >> n; //いらん
	while (cin >> s){
		if (s == "quit") break;
		else if (s == "push"){
			cin >> n;
			cin >> c;
			d[n].push(c);
		}
		else if (s == "pop"){
			cin >> n;
			cout << static_cast<char>(d[n].top()) << endl;
			d[n].pop();
		}
		else if (s == "move"){
			cin >> n;
			t = d[n].top();
			d[n].pop();
			cin >> n;
			d[n].push(t);
		}
	}
}