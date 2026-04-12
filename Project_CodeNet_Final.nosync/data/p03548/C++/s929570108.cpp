#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	int x,y,z;
	int ans=0;
	cin >> x >> y >> z;
	ans=(x-2*z)/(y+z);
	if((x-2*z)%(y+z)>=y)ans++;
	cout << ans << endl;
	return 0;
}
