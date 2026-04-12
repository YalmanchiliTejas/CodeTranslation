#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	vector<int> ans;

	for(int i=0;i<n;i++)
	{
		if(ans.empty() or ans[0]>=a[i])
		{
			ans.insert(ans.begin(),a[i]);
		}
		else if(ans[ans.size()-1]<a[i])
		{
			ans[ans.size()-1]=a[i];

		}
		else
		{
			auto itr=lower_bound(ans.begin(),ans.end(),a[i]);
			itr--;
			*itr=a[i];
		}
		
	}
	cout << ans.size() << endl;
//	for(int i=0;i<ans.size();i++)
//		cout << ans[i] << endl;





}
