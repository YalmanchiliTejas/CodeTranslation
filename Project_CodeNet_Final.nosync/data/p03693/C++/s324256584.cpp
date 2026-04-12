
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const ll INF=100000000000000LL;

int main() {
	int r,g,b;
	cin>>r>>g>>b;
	if((100*r+10*g+b)%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
