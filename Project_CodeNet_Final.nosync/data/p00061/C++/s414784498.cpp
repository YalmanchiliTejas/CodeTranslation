#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int team[128]={0};
	int score[128]={0};
	int rank[128]={0};
	
	int e = 1;
	bool f = true;
	while(f){
		f = true;
		scanf("%d,%d",&team[e],&score[e]);
		(team[e] == 0 && score[e] == 0) ? f = false : e++;
	}
	
	for(int i = 1; i <= e; i++){
		for(int j = i + 1; j <= e; j++){
			if(score[i] < score[j]){
				swap(score[i],score[j]);
				swap(team[i],team[j]);
			}
		}
	}
	
	int x = 1;
	rank[1] = 1;
	for(int i = 2; i <= e; i++){
		if(score[i-1] > score[i])x++;
		rank[i] = x;
	}
	
	int n;
	while(~scanf("%d",&n)){
		for(int i = 1; i <= e; i++){
			if(team[i] == n){
				printf("%d\n",rank[i]);
				break;
			}
		}
	}
	return 0;
}