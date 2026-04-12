#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main(){
	int a;
	int b;
	cin >> a>>b;
	if (a > b){
		cout << "a > b" << endl;
	}
	if (a < b){
		cout << "a < b" << endl;
	}
	if (a == b){
		cout << "a == b" << endl;
	}

	return 0;
}