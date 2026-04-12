#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;
 
vector<list<int>> graph;
set<int> willvisit;
int numpath = 0;
void go(int n)
{
	int t;
	set<int>::iterator it;
	it = willvisit.find(n);
	t = *it;
	willvisit.erase(it);
	if (willvisit.size() == 0)
	{
		numpath++;
		willvisit.insert(t);
		return;
	}
	for (int x : graph[n])
	{
		if ((it=willvisit.find(x)) != willvisit.end())
		{
		
			go(x);
			
		}
	}
	willvisit.insert(t);
}
int main()
{
	int N, M;
	cin >> N >> M;
	graph.resize(N+1);
	for (int i = 1; i <= N; i++)
		willvisit.insert(i);
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	go(1);
	cout << numpath << endl;
	return 0;
}
