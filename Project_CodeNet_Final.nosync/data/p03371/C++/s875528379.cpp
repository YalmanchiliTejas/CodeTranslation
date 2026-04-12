#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int a,b,c,x,y,n;
	vector<int> ans;
	cin >> a >> b >> c >> x >> y;
	ans.push_back(a*x+b*y);
	ans.push_back(2*c*(x>=y?x:y));
	ans.push_back(2*c*(x<=y?x:y)+(x>=y?(x-y)*a:(y-x)*b));
	sort(ans.begin(),ans.end());
	cout << ans[0] << endl;
	return 0;
}
