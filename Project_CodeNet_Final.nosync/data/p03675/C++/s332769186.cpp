#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	list <int> l;
	int n; cin>>n;
	int t; cin>>t;
	l.push_back(t);
	for (int i = 2; i <= n; ++i)
	{
		cin>>t;
		if(i %2 == 0)
			l.push_back(t);
		else
			l.push_front(t);	
	}
	if(n % 2 == 0){
		vector <int > v;
		for (list <int>:: iterator i = l.begin(); i !=  l.end() ; ++i)
		{
			v.push_back(*i);
		}
		for (int i = v.size() - 1; i >= 0; --i)
		{
			cout<<v[i]<<" ";
		}
	}
	else{
		for (list<int>::iterator i = l.begin(); i !=  l.end() ; ++i)
		{
			cout<<*i<<" ";
		}
	}
	cout<<endl;
	return 0;
}