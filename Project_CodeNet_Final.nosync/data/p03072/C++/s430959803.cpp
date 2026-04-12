#include <iostream>
using namespace std;


const int MAX_N = 100;

int H[MAX_N];

int main()
{
	int N, res = 0;

	scanf("%d", &N);
	
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", H + i);
		bool t = true;

		for(int j = 0; j < i; ++j)
		{
			if(H[j] > H[i])
			{
				t = false;
				break;
			}
		}

		res += t;
	}
	
	printf("%d\n", res);


	return 0;
}