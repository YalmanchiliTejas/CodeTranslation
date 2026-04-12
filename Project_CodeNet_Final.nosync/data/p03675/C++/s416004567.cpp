#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int x = n-1;
	while(1){
		if(x<0)break;
		b.push_back(a[x]);
		x-=2;
	}
	x = n%2;
	while(1){
		if(x>n-1)break;
		b.push_back(a[x]);
		x+=2;
	}
	for(int i=0;i<n-1;i++){
		cout << b[i] << " ";
	}
	cout << b[n-1] << endl;
	return 0;
}