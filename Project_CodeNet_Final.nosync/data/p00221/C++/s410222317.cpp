#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int m,n,a,i,j,cnt,cnt2;
	int flg[1001],flg2;
	int k; // 現在のプレイヤー
	int an[1001]; //答え
	string s;
	while(1){
		cin>>m>>n;
		for(i=1;i<=m;i++) flg[i]=0;
		flg[m+1]=0; k=1;
		if(m==0&&n==0) break;
		cnt2=0;
		for(i=1;i<=n;i++){
			//for(j=1;j<=m;j++) printf("%d ",flg[j]);
			//printf("\n");
			cin>>s;
			
			 // 残りのプレイヤーが一人ならばしたの処理をとばす
			if(cnt2==m-1) continue;
			
			  // flgを無視
			if(k>m){
				for(j=1;j<=m;j++){
					if(flg[j]==0){
						k=j; break;
					}
				}
			}
			
			if(i%3==0&&i%5==0){
				if(s[0]!='F'||s[4]!='B'){
					flg[k]=1; cnt2++;
				}
			}
			else if(i%3==0){
				if(s[0]!='F'){
					flg[k]=1; cnt2++;
				}
			}
			else if(i%5==0){
				if(s[0]!='B'){
					flg[k]=1; cnt2++;
				}
			}
			else{
				a=atoi(s.c_str());
				if(i!=a){
					flg[k]=1; cnt2++;
				}
			}
			
			  // flgを無視
			for(j=k+1;j<=m+1;j++){
				if(flg[j]==0){
					k=j; break;
				}
			}
			
		}
		//for(i=1;i<=m;i++) printf("%d ",flg[i]);
		//printf("\n");
		cnt=0;
		for(i=1;i<=m;i++){
			if(flg[i]==0){
				cnt++;
				an[cnt]=i;
			}
		}
		for(i=1;i<cnt;i++) printf("%d ",an[i]);
		printf("%d\n",an[cnt]);
	}
	return 0;
}
