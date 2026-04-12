#include <cstdio>

int main()
{
	while(true) {
	
		int n;
		
		scanf("%d", &n);
		if(n == 0)
			break;
	
		int up = 1, right = 3, front = 2;
		int sum = 1;
		
		for(int i = 0; i < n; ++i) {
		
			int t;
			char str[64], c;
			
			scanf("%s", str);
			c = str[0];
			
			if(c == 'N') {
			
				t = 7 - up;
				up = front;
				front = t;
			
			} else if(c == 'E') {
			
				t = 7 - right;
				right = up;
				up = t;
			
			} else if(c == 'S') {
			
				t = 7 - front;
				front = up;
				up = t;
			
			} else if(c == 'W') {
			
				t = 7 - up;
				up = right;
				right = t;
			
			} else if(c == 'R') {
			
				t = 7 - front;
				front = right;
				right = t;
			
			} else if(c == 'L') {
			
				t = 7 - right;
				right = front;
				front = t;
			}
			
			sum += up;
		}
		
		printf("%d\n", sum);
	}

	return 0;
}