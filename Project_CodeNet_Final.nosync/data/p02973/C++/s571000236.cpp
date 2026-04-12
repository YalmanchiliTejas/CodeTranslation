#include<bits/stdc++.h>
using namespace std;
int main()
{
	multiset<int> answer;
	int n,k; cin>>n;
	for(int i =0 ; i < n ; i++)
	{
		cin>>k;
		auto it = answer.lower_bound(k);
		if(it==answer.begin())
			 answer.insert(k);
		else
		{
			it--;
			answer.erase(it);
			answer.insert(k);
		}
	}
	cout<<answer.size()<<endl;
	return 0;
}