#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned long> layer(50);
vector<unsigned long> patty(50);

unsigned long burger(int n, unsigned long x){
	if(x<=0)
		return 0;
	else if (n == 0)
		return 1;
	else if(x <= 1+layer[n-1])
		return burger(n - 1, x - 1);
	else
		return patty[n - 1] + 1 + burger(n - 1, x - 2 - layer[n - 1]);
}

int main(){
	int n;
	unsigned long x;
	cin >> n >> x;
	layer[0] = 1;
	patty[0] = 1;

	for (int i = 0; i < n-1;i++){
		layer[i + 1] = 2 * layer[i] + 3;
		patty[i + 1] = 2 * patty[i] + 1;
	}

	cout << burger(n, x) << endl;
	return 0;
}
