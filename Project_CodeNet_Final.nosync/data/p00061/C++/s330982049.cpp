#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;

struct cell{
	int no;
	int n;
};

bool compare(const cell& left, const cell& right)
{
	return left.n > right.n ;
}

int main()
{
	vector<cell> team;
	cell c;
	int a, b, i, j;
	vector<int> rank;
	while (scanf("%d,%d", &a, &b), a||b) {
		c.no = a;
		c.n = b;
		team.push_back( c );
		rank.push_back( 0 );
	}
	rank.push_back( 0 );
	sort(team.begin(), team.end(), compare);
	rank[team[0].no] = 1;
	j = 0;
	for (i = 1; i < team.size(); i++) {
		if ( team[i].n == team[i-1].n ) j --;
		rank[team[i].no] = i + j + 1;
	}
	while (cin>>a) cout<<rank[a]<<endl;
	return 0;
}