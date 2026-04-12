//0061
#include<stdio.h>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

int main(void)
{
	map<int, int> i2s;
	map<int, int> s2r;	//d¡·éÊðêÂÉ·éæ¤
	int num,solvCount;
	while( scanf("%d,%d", &num, &solvCount), num)
	{
		i2s[num] = solvCount;
		s2r[solvCount] = 0;	//Æè ¦¸lðüêé¾¯
	}
	while(scanf("%d", &num) == 1)
	{
		int rank = 1;
		for(map<int, int>::iterator ite = s2r.begin();
			ite != s2r.end(); ++ite)
		{
			if(ite->first > i2s[num])
				rank++;
		}
		printf("%d\n", rank);
	}
	return 0;
}