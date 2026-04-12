#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> v;
	int n,a,ans=1;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}	

	a=v[0];

	for(int i=1;i<n;i++){
		if(v[i]>=a)ans++;
		if(v[i]>a)a=v[i];
	}

	cout << ans << endl;
	return 0;
}