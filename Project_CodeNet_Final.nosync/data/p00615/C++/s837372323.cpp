#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int n,m;
	while(cin>>n>>m){
		if(!(n||m)) break;
		int t[20000]={0};
		for(int i=0;i<n+m; i++){
			cin >> t[i];
		}
		sort(t, t + n+m-1);
		int max = t[0];
		for(int i=1; i<n+m; i++){
			if(t[i]-t[i-1]>max) max = t[i]-t[i-1];
		}
		cout << max << endl;
	}
	return 0;
}