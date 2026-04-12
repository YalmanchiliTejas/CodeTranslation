#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		if(!n)
			break;
		int p[100];
		for(int i=0;i<n;i++){
			cin >> p[i];
		}
		sort(p,p+n);
		int sum=0;
		for(int i=1;i<n-1;i++){
			sum += p[i];
		}
		cout << sum/(n-2) << endl;
	}
	return 0;
}