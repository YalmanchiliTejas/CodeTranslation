#include "bits/stdc++.h"
using namespace std;

int x,y,z,ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>x>>y>>z;
	ans = x / (y + z);
	if(ans * (y + z) + z > x)
		cout<<ans-1;
	else
		cout<<ans;
	return 0;
}