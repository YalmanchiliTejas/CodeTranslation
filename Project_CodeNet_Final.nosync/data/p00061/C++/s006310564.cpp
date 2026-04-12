#include<iostream>
#include<queue>
#include<utility>
#include<stdio.h>

typedef std::pair<int,int> P;

int main()
{
	std::priority_queue<P> pq;
	int t, a;
	int *ans;

	while( scanf( "%d,%d", &t, &a ), t | a )
		pq.push( std::make_pair( a, t ) );

	ans = new int [pq.size()+1];

	int prev = -1, now = 0;

	while( !pq.empty() )
	{
		P p = pq.top();
		pq.pop();

		if( p.first != prev )
			now++;

		ans[p.second] = now;
		prev = p.first;
	}

	int n;
	while( std::cin >> n )
		std::cout << ans[n] << std::endl;

	delete [] ans;

	return 0;
}