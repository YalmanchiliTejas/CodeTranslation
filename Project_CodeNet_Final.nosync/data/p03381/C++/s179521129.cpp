#include<bits/stdc++.h>
using namespace std;

int data[200005];
int pos[200005];
map<int,int> nn;

int main(){
	int ban;
	scanf("%d",&ban);
	double median=(double)(ban+1)/2;
	for(int i=1;i<=ban;i++){
		scanf("%d",&data[i]);
		pos[i]=data[i];
	}
	sort(pos+1,pos+ban+1);
	for(int i=1;i<=ban;i++){
		nn[pos[i]]=i;
	}
	for(int i=1;i<=ban;i++){
		if(nn[data[i]]<median){
			printf("%d\n",pos[(int)ceil(median)]);	
		}
		else{
			printf("%d\n",pos[(int)floor(median)]);
		} 
	}
}