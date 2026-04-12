#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <deque>

using namespace std;

#define reep(i,f,t) for(int i=f ; i<int(t) ; ++i)
#define rep(i,n) reep(i, 0, n) 

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void push(int light[10][10], int y, int x)
{
	const int dy[] = {-1, 0, 0, 0, 1};
	const int dx[] = {0, -1, 0, 1, 0};

	rep(i, 5){
		int py = y + dy[i];
		int px = x + dx[i];
		if(py<0 || 10<=py || px<0 || 10<=px)
			continue;
		light[py][px] = !light[py][px];
	}
}

void simulate(int tmp[10][10], int j, bool output)
{
	rep(k, 10){
		if((j>>k)&1){
			push(tmp, 0, k);
			if(output)
				printf("%s1", k?" ":"");
		}else if(output)
			printf("%s0", k?" ":"");
	}
	if(output)
		puts("");

	rep(k, 9){
		rep(l, 10){
			if(tmp[k][l]){
				push(tmp, k+1, l);
				if(output)
					printf("%s1", l?" ":"");
			}else if(output)
				printf("%s0", l?" ":"");
		}
		if(output)
			puts("");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	rep(i, n){
		int light[10][10];
		rep(j, 10) rep(k, 10)
			scanf("%d", &light[j][k]);

		rep(j, 1<<10){
			int tmp[10][10];
			rep(k, 10) rep(l, 10)
				tmp[k][l] = light[k][l];

			simulate(tmp, j, false);
			bool ok = true;
			rep(k, 10) rep(l, 10){
				if(tmp[k][l]){
					ok = false;
					k=10;
					break;
				}
			}

			if(ok){
				simulate(light, j, true);
				break;
			}
		}
	}

	return 0;
}