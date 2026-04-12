#include <cstdio>
#include <cstdlib>
//#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

int main(void){

	int n;
	while (cin >> n, n){
		priority_queue<int> result;

		for (int i = 0; i < n; i++){

			int buff; cin >> buff;
			result.push(buff);

		}
		
		long int num = 0;
		int i = 0;
		int buff = 0;

		result.pop();
		buff = result.top();
		result.pop();
		while (!result.empty()) {
			num += buff;
			buff = result.top();
			result.pop();
			i++;
		}

		cout << num / i << endl;
		
	}

	return 0;
}