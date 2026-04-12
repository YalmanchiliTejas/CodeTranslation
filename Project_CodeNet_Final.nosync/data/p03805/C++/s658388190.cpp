#include <bits/stdc++.h>
using namespace std;

int sb(int nm,vector<int> c,vector<int> d,vector<bool> x) {
	bool av = true;
	x.at(nm) = true;
	for(int i=0;i<x.size();i++)
	{
		if(x.at(i) == false)
		{
			av = false;
		}
	}
	if(av)
	{
		return 1;
	}
	int rt =0;
	for(int i =0;i<c.size();i++)
	{
		if(c.at(i) == nm + 1)
		{
			if(x.at(d.at(i) - 1))
			{
				continue;
			}
			else
			{
				//nm = d.at(i) - 1;
				//x.at(nm) = true;
				rt += sb(d.at(i)-1,c,d,x);
			}
		}
		else if(d.at(i) == nm + 1)
		{
			if(x.at(c.at(i) - 1))
			{
				continue;
			}
			else
			{
				//nm = c.at(i) - 1;
				//x.at(nm) = true;
				rt += sb(c.at(i)-1,c,d,x);
			}
		}
	}
	return rt;
}

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> a(m,0),b(m,0);
	vector<bool> v(n,false);
	for(int i = 0;i < m;i++)
	{
		cin >> a.at(i) >> b.at(i);
	}
	v.at(0) = true;
    cout << sb(0,a,b,v) << endl;
	return 0;
}
