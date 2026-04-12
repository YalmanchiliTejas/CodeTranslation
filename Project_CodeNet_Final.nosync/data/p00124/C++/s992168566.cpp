#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
#include<string>
using namespace std;

struct cell{
	string name;
	int n;
};

bool compare(const cell& left, const cell& right)
{
	return left.n > right.n ;
}

int main()
{
	vector<cell> team;
	vector<cell>::iterator it;
	cell c;
	int n, i;
	string s;
	int w, l, d;
	bool f = false;
	while (cin>>n, n) {
		if (f) cout<<endl;
		f = true;
		team.clear();
		for (i = 0; i < n; i++) {
			cin>>s>>w>>l>>d;
			c.name = s;
			c.n = 3*w+d;
			team.push_back( c );
		}
		sort(team.begin(), team.end(), compare);
		for (i = 0; i < n; i++)
			cout<<team[i].name<<","<<team[i].n<<endl;
	}
	return 0;
}