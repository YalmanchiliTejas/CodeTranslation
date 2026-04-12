#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

enum {
	OTHER = 0,
	THREE = 1,
	FIVE  = 2,
	THREEFIVE = 3,
};

int main( void )
{
	int m, n;
	char player[1000];
	while(cin >> m >> n, (m | n))
	{
		int alive = m;
		for(int i=0; i < m; i++) player[i] = 1;
		int pnt = 0, cnt = 1;
		char input[256];
		for(int i=0; i < n; i++) {
			scanf("%s", input);
			if(alive == 1) continue;
			int judge = 0;
			if(!(cnt % 3)) judge |= THREE;
			if(!(cnt % 5)) judge |= FIVE;
			switch(judge)
			{
			case OTHER:
				if(atoi(input) != cnt) {
					player[pnt] = 0; --alive;
				}
				break;
			case THREE:
				if(strcmp(input, "Fizz")) {
					player[pnt] = 0; --alive;
				}
				break;
			case FIVE:
				if(strcmp(input, "Buzz")) {
					player[pnt] = 0; --alive;
				}
				break;
			case THREEFIVE:
				if(strcmp(input, "FizzBuzz")) {
					player[pnt] = 0; --alive;
				}
				break;
			}
			cnt++;
			bool hit = false;
			for(int j=pnt+1; j < m; j++) {
				if(player[j]) {
					pnt = j;
					hit = true;
					break;
				}
			}
			if(!hit) {
				for(int j=0; j < pnt; j++) {
					if(player[j]) {
						pnt = j;
						break;
					}
				}
			}
		}
		for(int i=0; i < m; i++) {
			if(player[i]) {
				cout << i+1; --alive;
				if(alive) cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}