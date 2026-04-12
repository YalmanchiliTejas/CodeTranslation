#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Info{
	int color,succeed;
};

int main(){

	int n,white,black,tmp;
	Info info;
	stack<int> S;

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		info.succeed = 0;
		white = 0;
		black = 0;

		scanf("%d",&tmp);

		if(tmp == 0){
			white++;
			info.color = 0;
			info.succeed = 1;
		}else{
			black++;
			info.color = 1;
			info.succeed = 1;
		}

		for(int i = 2; i <= n; i++){
			scanf("%d",&tmp);

			if(tmp == 0){
				white++;
			}else{
				black++;
			}

			if(i % 2 == 1){
				if(info.color == tmp){
					info.succeed++;
				}else{
					S.push(info.succeed);
					info.succeed = 1;
					info.color = tmp;
				}
			}else{
				if(info.color == tmp){
					info.succeed++;
				}else{
					if(tmp == 0){
						black -= info.succeed;
						white += info.succeed;
						if(!S.empty()){
							info.succeed += S.top();
							S.pop();
						}
						info.color = 0;
						info.succeed++;
					}else{
						black += info.succeed;
						white -= info.succeed;
						if(!S.empty()){
							info.succeed += S.top();
							S.pop();
						}
						info.color = 1;
						info.succeed++;
					}
				}
			}
		}
		while(!S.empty())S.pop();
		printf("%d\n",white);
	}
    return 0;
}