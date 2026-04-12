#include <iostream>
#include <map>
using namespace std;
int main()
{
	multimap<int,int> score;
	multimap<int,int>::reverse_iterator mp,lb,ub;
	while(1)
	{
		int m,n; char ch; cin >> n >> ch >> m ;
		if(m==0 && n==0) break;
		score.insert(pair<int,int>(m,n));
	}
	int rank[101]={0}; int r=1;
	mp=score.rbegin(); int tmp=mp->first;
	for( ;mp!=score.rend();mp++)
	{
		if(tmp!=mp->first) {tmp=mp->first; rank[mp->second]=++r;}
		else rank[mp->second]=r;
	}
	int an;
	//for(int i=1;i<100;i++) cout << rank[i] << ' ' ; cout << endl;
	while(cin>>an) { cout << rank[an] << endl; }
}