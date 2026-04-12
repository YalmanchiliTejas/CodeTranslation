#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


/*void printvec(vector<int> v) {
	int a = v.size();
	for (int i = 0; i < a; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}*/


int main(){
	int N, M;
	cin >> N >> M;
	if (N == M)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
    return 0;
}