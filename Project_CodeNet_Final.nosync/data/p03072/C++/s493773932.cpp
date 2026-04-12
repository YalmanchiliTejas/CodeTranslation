#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;

	int maxH  = 0;
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		int h;
		cin >> h;
		if(maxH <= h){
			maxH = h;
			ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}
