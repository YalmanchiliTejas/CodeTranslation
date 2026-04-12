#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;

#define BIG_NUM 2000000000

using namespace std;


int main(){

	bool FLG = false;
	int N,T,E;
	scanf("%d %d %d",&N,&T,&E);
	int tmp,calc;

	for(int i = 0; i < N; i++){
		scanf("%d",&tmp);

		if(!FLG)
		{
			calc = tmp;
			while(calc <= T+E){
				if(abs(T-calc) <= E){
					FLG = true;
					printf("%d\n",i+1);
					break;
				}
				calc += tmp;
			}
		}
	}

	if(!FLG)printf("-1\n");

    return 0;
}