#include <cstdio>
#include <stack>

using namespace std;

typedef struct{
	int color;
	int num;
} Stone;

int opcolor(int color){
	return 1 - color;
}

stack<Stone> st;
int n;

int main(){
	while(scanf("%d",&n), n != 0){
		//init
		st = stack<Stone>();
		Stone init_stone = {0,0};
		st.push(init_stone);

		// put
		for(int i = 1; i <= n; i++){
			int c;
			scanf("%d",&c);
			if( i % 2 == 0){
				Stone bef = st.top();st.pop();
				if(c == bef.color){
					bef.num++;
					st.push(bef);
				}
				else{
					if(!st.empty()){
						Stone befbef = st.top();st.pop();
						befbef.num += bef.num + 1;
						st.push(befbef);
					}
					else{
						bef.color = c;
						bef.num++;
						st.push(bef);
					}
				}
			}
			else{
				Stone bef = st.top();st.pop();
				if(c == bef.color){
					bef.num++;
					st.push(bef);
				}
				else{
					st.push(bef);
					Stone ns = {c,1};
					st.push(ns);
				}
			}
		}
		//count white(0) 
		int ans = 0;
		while(!st.empty()){
			Stone s = st.top();st.pop();
			if(s.color == 0){
				ans += s.num;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

