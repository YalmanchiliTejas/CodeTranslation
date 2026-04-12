#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

int main() {

	int a;
	cin >> a;
	int b;
	int cur = 0;
	int ct = 0;
	for(int i=0; i<a; i++){
		cin >> b;
		if(b >= cur){
			ct += 1;
			cur = b;
		}
	}
	cout << ct;
}