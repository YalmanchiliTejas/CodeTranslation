#include<bits/stdc++.h>
using namespace std;
inline char res(char l,char name,char w){
	if(name=='S'&&w=='o')return l;
	if(name=='W'&&w=='x')return l;
	if(l=='S')return 'W';
	else return 'S';
} 
int n;
int main(){
cin>>n;
char w[n],name[n],l;
for(int i=0;i<n;i++){
	cin>>w[i];
}
name[0]='S';
name[1]='S';
for(int i=1;i<n-1;i++){
	name[i+1]=res(name[i-1],name[i],w[i]);
}
if(name[0]==res(name[n-2],name[n-1],w[n-1])&&name[1]==res(name[n-1],name[0],w[0])){
	for(int i=0;i<n;i++){
		cout<<name[i];
	}
	return 0;
}
name[0]='S';
name[1]='W';
for(int i=1;i<n-1;i++){
	name[i+1]=res(name[i-1],name[i],w[i]);
}
if(name[0]==res(name[n-2],name[n-1],w[n-1])&&name[1]==res(name[n-1],name[0],w[0])){
	for(int i=0;i<n;i++){
		cout<<name[i];
	}
	return 0;
}
name[0]='W';
name[1]='S';
for(int i=1;i<n-1;i++){
	name[i+1]=res(name[i-1],name[i],w[i]);
}
if(name[0]==res(name[n-2],name[n-1],w[n-1])&&name[1]==res(name[n-1],name[0],w[0])){
	for(int i=0;i<n;i++){
		cout<<name[i];
	}
	return 0;
}
name[0]='W';
name[1]='W';
for(int i=1;i<n-1;i++){
	name[i+1]=res(name[i-1],name[i],w[i]);
}
if(name[0]==res(name[n-2],name[n-1],w[n-1])&&name[1]==res(name[n-1],name[0],w[0])){
	for(int i=0;i<n;i++){
		cout<<name[i];
	}
	return 0;
}
cout<<-1;
return 0;
}