#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int n,max=0,sum=0;
	cin >> n;
	vector<int> h(n);
	
	for(int i=0;i<n;i++){
		cin >> h[i];
		if(h[i] >= max){
			sum ++;
			max = h[i];
		}
	}
	cout << sum << endl;
	
	
	return 0;
}
