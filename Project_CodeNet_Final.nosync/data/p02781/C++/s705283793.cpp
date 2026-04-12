#include<bits/stdc++.h>
using namespace std;
int num,n,m,w,k;
long long ans=0;
string x;
void func(int a,int b,int c){
	string temp="";
	for(int i=0;i<num;i++)
		temp+='0';
	if(b==999){
		for(int i='1';i<='9';i++){
			temp[a]=i;
			if(temp<=x)
				ans++;
		}
		return;
	}
	else if(c==999){
		for(int i='1';i<='9';i++)
			for(int j='1';j<='9';j++){
				temp[a]=i;
				temp[b]=j;
				if(temp<=x)
					ans++;
			}
		return; 
	}
	for(int i='1';i<='9';i++)
		for(int j='1';j<='9';j++)
			for(int f='1';f<='9';f++){
				temp[a]=i;
				temp[b]=j;
				temp[c]=f;
				if(temp<=x)
					ans++;
			}
	return;
}
int main(){
	cin>>x>>k;
	num=x.size();
	if(k==1){
		for(int i=0;i<num;i++)
			func(i,999,999);
		cout<<ans;
		return 0;
	}
	else if(k==2){
		for(int i=1;i<num;i++)
			for(int j=0;j<i;j++)
				func(j,i,999);
		cout<<ans;
		return 0;
	}
	for(int i=2;i<num;i++)
		for(int j=1;j<i;j++)
			for(int f=0;f<j;f++)
				func(f,j,i);
	cout<<ans;
	return 0; 
}