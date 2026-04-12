#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Tm
{
	int point;
	string name;
	Tm(string s, int p){name=s;point=p;}
	bool operator<(const Tm &t) const
	{
		return point>t.point;
	}
};

int main()
{
	bool f=false;
	int n,a,b,c;
	string str;

	while(cin >> n, n)
	{
		if(f) cout << endl; f=true;

		vector<Tm> v;
		while(n--)
		{
			cin >> str >> a >> b >> c;
			v.push_back(Tm(str,a*3+c));
		}
		stable_sort(v.begin(), v.end());

		for(int i=0; i<v.size(); i++)
		{
			cout << v[i].name << "," << v[i].point << endl;
		}
	}
}