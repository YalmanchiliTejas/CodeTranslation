#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int c200=n/15;
	int ans=800*n-200*c200;
	cout << ans << endl;				
	return 0;
}
