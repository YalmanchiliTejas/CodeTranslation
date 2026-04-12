#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return w*x;
}
int main(){
	string ptr;
	cin>>ptr;
	int a=0,b=0;
	for(int i=0;i<ptr.length();i++){
		if(ptr[i]=='A'){
			a++;
		}
		if(ptr[i]=='B'){
			b++;
		}
	}
	if(a&&b){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}