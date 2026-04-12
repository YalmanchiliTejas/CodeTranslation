#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c;
	int x, y;
	cin>>a>>b>>c>>x>>y;
	c*=2;

	int ans;
	if(a+b<c) {
		ans=a*x+b*y;
	}
	else {
		if(x>y)ans=min(c*y+a*(x-y),c*x);
		else ans=min(c*x+b*(y-x),c*y);
	}

	cout<<ans<<endl;

	return 0;
}
