#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int loop_num;
		char buf[12];
	while (1){
		int up = 1, down = 6, South = 2, West = 4, North = 5, East = 3;
		long long ans = 0;
		scanf("%d", &loop_num);
		if (loop_num == 0) return 0;
		for (int a = 0; a < loop_num; a++){
			scanf("%s", buf);
			switch (buf[0])
			{
			case 'N':
				swap(up, South);
				swap(South, down);
				swap(down, North);
				break;
			case 'E':
				swap(up, West);
				swap(West, down);
				swap(down, East);
				break;
			case 'W':
				swap(up, East);
				swap(East, down);
				swap(down, West);
				break;
			case 'S':
				swap(up, North);
				swap(North, down);
				swap(down, South);
				break;
			case 'R':
				swap(North, West);
				swap(West, South);
				swap(South, East);
				break;
			case 'L':
				swap(North, East);
				swap(East, South);
				swap(South, West);
				break;
			default:
				break;
			}
			ans+=up;
		}
		printf("%lld\n", ans + 1);
	}
}