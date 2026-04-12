
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const ll INF=100000000000000LL;

int main() {
	int x,y,z;
	cin>>x>>y>>z;
	int ans=0;
	ans=x/(z+y);
	if(x%(y+z)<z)ans--;
	cout<<ans<<endl;
	return 0;
}
