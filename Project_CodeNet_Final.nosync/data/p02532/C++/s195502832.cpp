#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	char q[128], x[128];
	int n, m;
	stack<char> st[128];
	
	scanf("%d", &n);
	
	while (1){
		scanf("%s", q);
		
		if (q[0] == 'q') break;
		
		if (q[0] == 'p' && q[1] == 'u'){
			scanf("%d %s", &m, x);
			st[m - 1].push(x[0]);
		}
		else if (q[0] == 'p'){
			scanf("%d", &m);
			printf("%c\n", st[m - 1].top());
			st[m - 1].pop();
		}
		else {
			int p1, p2;
			scanf("%d %d", &p1, &p2);
			st[p2 - 1].push(st[p1 - 1].top());
			st[p1 - 1].pop();
		}
	}
	
	return (0);
}