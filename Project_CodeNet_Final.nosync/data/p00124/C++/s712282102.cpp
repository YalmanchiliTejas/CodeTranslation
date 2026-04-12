#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
pair<int,int> dat[10];
char p[10][21];
int main(){
	int a;
	bool saisho=true;
	while(scanf("%d",&a),a){
		if(!saisho)printf("\n");
		saisho=false;
		for(int i=0;i<a;i++){
			int b,c,d;
			scanf("%s%d%d%d",p[i],&b,&c,&d);
			dat[i]=make_pair(-(b*3+d),i);
		}
		std::sort(dat,dat+a);
		for(int i=0;i<a;i++){
			printf("%s,%d\n",p[dat[i].second],-dat[i].first);
		}
	}
}