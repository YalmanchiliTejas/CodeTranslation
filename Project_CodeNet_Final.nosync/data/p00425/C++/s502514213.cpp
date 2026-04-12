#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,sum,i,j;
	char meirei[8];
	
	while(cin>>n,n){
		sum = 1;
		int map[3] = {1,2,3};
		while(n--){
			cin>>meirei;
			int tmp;
			if      ( !strcmp(meirei,"North") ){
				tmp = map[0];
				map[0] = map[1];
				map[1] = 7 - tmp;
				sum += map[0];
				
			}else if( !strcmp(meirei,"East") ){
				tmp = map[2];
				map[2] = map[0];
				map[0] = 7 - tmp;
				sum += map[0];
				
			}else if( !strcmp(meirei,"South") ){
				tmp = map[1];
				map[1] = map[0];
				map[0] = 7 - tmp;
				sum += map[0];
				
			}else if( !strcmp(meirei,"West") ){
				tmp = map[0];
				map[0] = map[2];
				map[2] = 7 - tmp;
				sum += map[0];
				
			}else if( !strcmp(meirei,"Right") ){
				tmp = map[1];
				map[1] = map[2];
				map[2] = 7 - tmp;
				sum += map[0];
				
			}else if( !strcmp(meirei,"Left") ){
				tmp = map[2];
				map[2] = map[1];
				map[1] = 7 - tmp;
				sum += map[0];
			}
			//printf("%d,%d,%d  sum_%d\n",map[0],map[1],map[2],sum);
		}
		printf("%d\n",sum);
	}
	return 0;
}