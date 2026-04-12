#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(void){
	int m,n,flg[1001],i,j,cnt,h,list[1000],ff,mm,len,p;
	char s[10001][21],f[]="Fizz",b[]="Buzz",fb[]="FizzBuzz";
	while(1){
		cin>>m>>n;
		if(m==0) break;
		for(i=1;i<=m;i++) flg[i]=1;
		for(i=1;i<=n;i++) cin>>s[i];
		cnt=0; p=1;
		for(i=1;i<=n;i++){
			if(m-cnt==1){
//				cout<<i<<endl;
				break;
			}
			if(flg[p]==0){
				while(flg[p]!=1){
					p++;
					if(p>m) p=1;
				}
			}
			if(i%3==0&&i%5==0){
				if(strcmp(s[i],fb)!=0){
					flg[p]=0;
					cnt++;
				}
			}
			else if(i%3==0&&i%5!=0){
				if(strcmp(s[i],f)!=0){
					flg[p]=0;
					cnt++;
				}
			}
			else if(i%5==0&&i%3!=0){
				if(strcmp(s[i],b)!=0){
					flg[p]=0;
					cnt++;
				}
			}
			else{
				mm=atoi(s[i]);
				if(mm!=i){
					flg[p]=0;
					cnt++;
				}
			}
			p++;
		}
		cnt=0;
		for(i=1;i<=m;i++){
			if(flg[i]==1){
				list[cnt]=i;
				cnt++;
			}
		}
		cout<<list[0];
		for(i=1;i<cnt;i++) cout<<' '<<list[i];
		cout<<endl;
	}
	return 0;
}