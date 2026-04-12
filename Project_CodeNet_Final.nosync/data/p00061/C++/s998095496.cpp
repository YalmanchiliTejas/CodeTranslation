#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int ,int> table[100000];
int COUNT[31];
int main(){
	int a,b;
	int index=0;
	while(scanf("%d,%d",&a,&b),a+b){
		table[index++]=make_pair(a,b);
		COUNT[b]++;
	}
	std::sort(table,table+index);
	int c;
	while(~scanf("%d",&c)){
		int at=lower_bound(table,table+index,make_pair(c,0))-table;
		int sum=0;
		for(int i=table[at].second+1;i<=30;i++)if(COUNT[i])sum++;
		printf("%d\n",sum+1);
	}
}