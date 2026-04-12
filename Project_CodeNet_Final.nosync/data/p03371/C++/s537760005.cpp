#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int A,B,C,X,Y;
	int ans=2e9;
	
	cin >> A >> B >> C >> X >> Y;
	
	for(int k=0;k<=2*max(X,Y);k++)
		ans=min(max((X-k/2)*A,0)+max((Y-k/2)*B,0)+k*C,ans);
	
	cout << ans << endl;
	return 0;
}
