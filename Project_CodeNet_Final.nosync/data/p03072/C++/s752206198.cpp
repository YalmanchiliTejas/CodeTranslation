#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;	
	
int main()
{
	int n,tmp=0;
	int ans = 0;
	
	cin >> n;
	
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
		if(v[i] >= tmp){
			ans++;
			tmp = v[i];
		}
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}