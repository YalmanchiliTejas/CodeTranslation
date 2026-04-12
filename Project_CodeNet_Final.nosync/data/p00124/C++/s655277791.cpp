#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair

using namespace std;

struct Team
{
	int point;
	int num;
	string name;

	bool operator< (const Team& t)const
	{
		return point == t.point ?  num < t.num : point < t.point;
 	}

};

int main()
{
	int n;
	bool fisrt = true;
	while(cin >> n && n)
	{

		if(fisrt)
		{
			fisrt = false;
		}
		else
		{
			cout << endl;
		}
		priority_queue<Team> q;
		string s;
		int a,b,c;
		rep(i,n)
		{
			cin >> s >> a >> b >> c;
			Team t;
			t.point = 3*a + c;
			t.num = n-i;
			t.name = s;
			
			q.push(t);
		}

		rep(i,n)
		{
			cout << q.top().name << "," << q.top().point << endl;
			q.pop();
			
		}
		
	}
	return 0;
}