
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;


bool solve(){

	stack<char> st[110];
	
	int n;
	cin>> n;
	while(1){
		string str;
		cin>> str;
		if(str == "quit") return true;
		if(str == "push"){
			int i;
			char c;
			cin>> i>> c;
			st[i].push(c);
		}else
		if(str == "pop"){
			int i;
			cin>> i;
			cout<< st[i].top()<<endl;
			st[i].pop();
		}else
		if(str == "move"){
			int i,j;
			cin>> i>> j;
			st[j].push(st[i].top());
			st[i].pop();
		}
	}
	
	
	return false;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

 