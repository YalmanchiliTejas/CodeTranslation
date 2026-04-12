#include <stdio.h>
#include <deque>
using namespace std;

deque<int> Q;

int main()
{
	int N;
	scanf ("%d",&N);
	for (int i=0,x;i<N;i++){
		scanf ("%d",&x);
		if (i % 2) Q.push_front(x);
		else Q.push_back(x);
	}

	if (N % 2) for (int i=N-1;i>=0;i--) printf ("%d%c",Q[i],i?' ':'\n');
	else for (int i=0;i<N;i++) printf ("%d%c",Q[i],i+1<N?' ':'\n');
	return 0;
}