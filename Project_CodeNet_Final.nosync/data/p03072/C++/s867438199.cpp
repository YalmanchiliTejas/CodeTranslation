#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int ans[105], n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> ans[i];
	int M = ans[0];
	int cnt = 1;
	for(int i = 1; i < n; i++) 
	{
		if(ans[i] == M) cnt++;
		else if(ans[i] > M) { M = ans[i]; cnt++; }
	}
	cout << cnt << endl;
	return 0;
}