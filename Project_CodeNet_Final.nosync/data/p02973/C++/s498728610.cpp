#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<string,int> P;
const ll MOD=1e9+7;
multiset<int> st;
int a[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	st.insert(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]<=(*st.begin()))
		{
			st.insert(a[i]);
		}else{
			auto p=st.lower_bound(a[i]);
			p--;
			st.erase(p);
			st.insert(a[i]);
		}
	}
	cout<<st.size()<<endl;
	return 0;
}