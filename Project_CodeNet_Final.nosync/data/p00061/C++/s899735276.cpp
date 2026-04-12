#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	int ct=0,temp,q,i;
	int p[101],s[101];
	int rank[101];
	
	while(scanf("%d,%d",&p[ct],&s[ct])){
		if(p[ct]==0&&s[ct]==0)
		break;
		ct++;
	}
	for(i=0;i<ct;i++){
		for(int j=i+1;j<ct;j++){
			if(s[i]<s[j]){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	rank[0]=1;
	temp = 1;
	for(i=1;i<ct;i++){
		if(s[i-1]!=s[i]){
			temp++;
			rank[i]=temp;
		}
		else
		rank[i]=temp;
	}
	while(scanf("%d",&q)!=EOF){
		for(int i=0;i<ct;i++){
			if(q==p[i]){
				printf("%d\n",rank[i]);
				break;
			}
		}
	}
}