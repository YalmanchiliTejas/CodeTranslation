#include <cstdio>
#include<iostream>

#define NMAX 100

using namespace std;
   
int main(void){

	int score[NMAX+1]={0};
	int rank[NMAX+1];
	int max,cnt;
	int num,dat;
	int ra;
	char ch;

	while(1){
		cin>>num>>ch>>dat;
		if(num==0&&dat==0) break;
		score[num]+=dat;
	}
	ra=1;
	while(1){
		cnt=0,max=-1;
		for(int i=1;i<=NMAX;i++){
			if(score[i]==-1) cnt++;
			else if(max<score[i]) max=score[i];
		}
		if(cnt==NMAX) break;
		for(int i=1;i<=NMAX;i++){
			if(score[i]==max){
				rank[i]=ra;
				score[i]=-1;
			}
		}
		ra++;
	}

	int inp;

	while(cin>>inp){
		cout<<rank[inp]<<endl;
	}

    return 0;
}