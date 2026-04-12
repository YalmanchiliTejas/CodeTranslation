#include <bits/stdc++.h>

using namespace std;

int n;

deque< int > s;

int main()
{
	scanf("%d",&n);

	for(int i = 1 ; i <= n ; i++)
	{
		int v;
		scanf("%d",&v);

		if( i%2 == 1 ) s.push_back( v );
		else s.push_front( v ); 
	}

	for(int i = 1 ; i <= n ; i++)
	{
		if( n%2 == 0 )
		{
			printf("%d ",s.front());
			s.pop_front();
		}
		else
		{
			printf("%d ",s.back());
			s.pop_back();
		}
	}
}