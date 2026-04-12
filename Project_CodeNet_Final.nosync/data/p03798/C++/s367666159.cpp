#include<bits/stdc++.h>
using namespace std;
int n,i,a[100001];
char l[100001];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)cin>>l[i];
	a[1]=0;a[2]=0;
	for(i=3;i<=n;i++){
		if(l[i-1]=='o'){
			if(a[i-1]){
				a[i]=1-a[i-2];
			}else{
				a[i]=a[i-2];
			}
		}else{
			if(a[i-1]){
				a[i]=a[i-2];
			}else{
				a[i]=1-a[i-2];
			}
		}
	}
	int s,s1;
	if(l[1]=='o'){
		s=a[2];
	}else s=1-a[2];
	if(l[n]=='o'){
		if(a[n]){
			s1=1-a[1];
		}else s1=a[1];
	}else{
		if(a[n]){
			s1=a[1];
		}else s1=1-a[1];
	}
	if(s==a[n]&&s1==a[n-1]){
		for(i=1;i<=n;i++){
			if(a[i])cout<<'W';else cout<<'S';
		}
		cout<<endl;
		return 0;
	}
	a[1]=0;a[2]=1;
	for(i=3;i<=n;i++){
		if(l[i-1]=='o'){
			if(a[i-1]){
				a[i]=1-a[i-2];
			}else{
				a[i]=a[i-2];
			}
		}else{
			if(a[i-1]){
				a[i]=a[i-2];
			}else{
				a[i]=1-a[i-2];
			}
		}
	}
	if(l[1]=='o'){
		s=a[2];
	}else s=1-a[2];
	if(l[n]=='o'){
		if(a[n]){
			s1=1-a[1];
		}else s1=a[1];
	}else{
		if(a[n]){
			s1=a[1];
		}else s1=1-a[1];
	}
	if(s==a[n]&&s1==a[n-1]){
		for(i=1;i<=n;i++){
			if(a[i])cout<<'W';else cout<<'S';
		}
		cout<<endl;
		return 0;
	}
	a[1]=1;a[2]=0;
	for(i=3;i<=n;i++){
		if(l[i-1]=='o'){
			if(a[i-1]){
				a[i]=1-a[i-2];
			}else{
				a[i]=a[i-2];
			}
		}else{
			if(a[i-1]){
				a[i]=a[i-2];
			}else{
				a[i]=1-a[i-2];
			}
		}
	}
	if(l[1]!='o'){
		s=a[2];
	}else s=1-a[2];
	if(l[n]=='o'){
		if(a[n]){
			s1=1-a[1];
		}else s1=a[1];
	}else{
		if(a[n]){
			s1=a[1];
		}else s1=1-a[1];
	}
	if(s==a[n]&&s1==a[n-1]){
		for(i=1;i<=n;i++){
			if(a[i])cout<<'W';else cout<<'S';
		}
		cout<<endl;
		return 0;
	}
	a[1]=1;a[2]=1;
	for(i=3;i<=n;i++){
		if(l[i-1]=='o'){
			if(a[i-1]){
				a[i]=1-a[i-2];
			}else{
				a[i]=a[i-2];
			}
		}else{
			if(a[i-1]){
				a[i]=a[i-2];
			}else{
				a[i]=1-a[i-2];
			}
		}
	}
	if(l[1]!='o'){
		s=a[2];
	}else s=1-a[2];
	if(l[n]=='o'){
		if(a[n]){
			s1=1-a[1];
		}else s1=a[1];
	}else{
		if(a[n]){
			s1=a[1];
		}else s1=1-a[1];
	}
	if(s==a[n]&&s1==a[n-1]){
		for(i=1;i<=n;i++){
			if(a[i])cout<<'W';else cout<<'S';
		}
		cout<<endl;
		return 0;
	}
	cout<<"-1";
	return 0;
}


