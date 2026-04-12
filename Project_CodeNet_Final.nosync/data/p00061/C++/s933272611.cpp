#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int main(){


	int data[101];
	int flag[31];

	for(int i=0;i<=30;i++){
		flag[i]=0;
	}
	int cnt=0;
	data[0]=0;
	while(1){
		int num,ansNum;
		scanf("%d,%d",&num,&ansNum);

		if(num==0&&ansNum==0)break;
		cnt++;

		data[num]=ansNum;
	}

	int i;
	while(cin>>i){
		int ans=1;
		int tmpNum=0;
		for(int j=0;j<=30;j++){
			flag[j]=0;
		}
		for(int j=0;j<=cnt;j++){
			if(i==j)continue;


			if(data[j]>=0&&data[i]<data[j]&&flag[data[j]]==0){
				ans++;
				flag[data[j]]++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}