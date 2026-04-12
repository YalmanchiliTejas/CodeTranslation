#include <iostream>
#include <queue>
using namespace std;

int n,a;
deque<int> b;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(i%2==0) b.push_back(a); else b.push_front(a);
	}
	
	if(n%2==0) while(!b.empty()) {cout<<b.front()<<' ';b.pop_front();}
	else while(!b.empty()) {cout<<b.back()<<' ';b.pop_back();}
	
	return 0;
}