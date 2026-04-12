#include<iostream>
#include<deque>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
	int n,s;
	while(cin>>n,n)
	{
		deque<int>d(n);
		while(n--)cin>>s,d[n]=s;
		sort(d.begin(),d.end());
		d.pop_back(),d.pop_front();
		cout<<accumulate(d.begin(),d.end(),0)/d.size()<<endl;
	}
	return 0;
}