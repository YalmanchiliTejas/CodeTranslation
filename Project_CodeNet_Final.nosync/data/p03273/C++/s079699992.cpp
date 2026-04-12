#include<bits/stdc++.h>
using namespace std;
char s[105][105];
int a[105],b[105];
int n,m;//行与列 
int t,d,k;//标记
int i,j;//循环变量 
int main(){
//	freopen("in.txt","r",stdin);
    cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	for(i=1;i<=n;i++){
		t=0;
		for(j=1;j<=m;j++){
			if(s[i][j]=='.'){
				t++;
			}
		}
		if(t==m){
		    a[i]=1;//如果‘.’个数等于行的格数，就代表这一行都是‘.’ 
	    }//判断行完毕 
	
	}

	//------------------------------------------------------------
	//开始判断列
	for(i=1;i<=m;i++) {
		d=0; 
		for(j=1;j<=n;j++){
			if(s[j][i]=='.'){
				d++;
			}
		}
		if(d==n){
		    b[i]=1;
        }
	}

	//----------------------------------------------
	//开始删除
	 for(i=1;i<=n;i++){
	 	k=0;
	 	for(j=1;j<=m;j++){
	 		if(a[i]||b[j]){
	 			continue;//有一行满足，越过不打印（相当于删除） 
			 }
			 k=1;
			 cout<<s[i][j];//输出跃过后的队列 
		 }
		 if(k==1){//删去间隔 
	 	     cout<<endl; 
	     } 
	 }
	 return 0;  
}