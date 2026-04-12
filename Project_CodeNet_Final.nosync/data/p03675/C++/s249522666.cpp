#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int a[200005];
	
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> a[i];
	}
	
	vector<int> vec;
	
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) vec.push_back(a[i]);
		else vec.insert(vec.begin(), a[i]);
	}
	
	if(n % 2) reverse(vec.begin(), vec.end());
	for(int i = 0; i < (int)vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
	
	return 0;
}