#include <cstdio>
#include <stack>
using namespace std;
struct Stone {
	bool color;
	int num;
	Stone(bool _col,int _num) {color=_col,num=_num;}
};
int main() {
	int n;
	while(scanf("%d",&n),n) {
		stack<Stone> stone;
		bool c;
		scanf("%d",&c);
		stone.push(Stone(c,1));
		for(int i=1;i<n;i++) {
			bool c;
			scanf("%d",&c);
			Stone S(stone.top()); stone.pop();
			if((i&1)==0) {
				if(S.color^c) {
					stone.push(S);
					stone.push(Stone(c,1));
				}else {
					S.num++;
					stone.push(S);
				}
			}else {
				if(S.color^c) {
					if(stone.size()) {
						Stone _S(stone.top()); stone.pop();
						stone.push(Stone(c,S.num+_S.num+1));
					}else {
						stone.push(Stone(c,S.num+1));
					}
				}else {
					S.num++;
					stone.push(S);
				}
			}
		}
		int sum=0;
		while(stone.size()) {
			Stone S(stone.top()); stone.pop();
			if(!S.color) sum+=S.num;
		}
		printf("%d\n",sum);
	}
}