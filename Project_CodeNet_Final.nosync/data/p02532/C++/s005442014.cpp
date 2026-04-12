#include <cstdio>
#include <stack>
using namespace std;

int main(){
	stack<char> st[101];
	char op[64] = "";
	int n, p, q;
	char c;
	scanf("%d\n", &n);
	while(1){
		fgets(op, 64, stdin);
		if(op[2] == 's'){
			sscanf(op, "%*s%d %c", &p, &c);
			st[p].push(c);
		}
		else if(op[2] == 'p'){
			sscanf(op, "%*s%d", &p);
			printf("%c\n", st[p].top());
			st[p].pop();
		}
		else if(op[0] == 'm'){
			sscanf(op, "%*s%d%d", &p, &q);
			c = st[p].top();
			st[p].pop();
			st[q].push(c);
		}
		else{
			break;
		}
	}
}