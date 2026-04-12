#include<string>
//#include <vector>
//#include <stack>
#include <set>
#include<iostream>
#include <algorithm>
#include <limits.h>
#include <float.h>
#include <functional>
#include <math.h>
#include <hashtable.h>

using namespace std;
string s;

set<char> rmap;

bool isRight(char s){
	return rmap.find(s)!=rmap.end();
}

int main(){
	rmap.insert('q');
	rmap.insert('w');
	rmap.insert('e');
	rmap.insert('r');
	rmap.insert('t');
	rmap.insert('a');
	rmap.insert('s');
	rmap.insert('d');
	rmap.insert('f');
	rmap.insert('g');
	rmap.insert('z');
	rmap.insert('x');
	rmap.insert('c');
	rmap.insert('v');
	rmap.insert('b');

	while(true){
		cin >> s;
		if(s=="#"){
			break;
		}
		int c=0;
		bool nowRight=isRight(s[0]);
		for(int i=1,ln=s.length();i<ln;i++){
			bool r=isRight(s[i]);
			if((nowRight && !r) || (!nowRight && r)){
				c++;
				nowRight=r;
			}
		}
		cout<< c << endl;
	}
}