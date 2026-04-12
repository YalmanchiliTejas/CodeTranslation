#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

int n[100000],s[100000],m;

int main(){
	int c=0;
	while(scanf("%d,%d",&n[c],&s[c])){
		if(n[c]+s[c]==0)break;
		c++;
	}
	int p=1;
	for(int i=30;i>=0;i--){
		int flag=0;
		for(int j=0;j<c;j++){
			if(s[j]==i){s[j]=p+100;flag=1;}
		}
		if(flag==1)p++;
	}
	while(scanf("%d",&m)!=EOF){
		for(int i=0;i<c;i++)if(n[i]==m){
			cout<<s[i]-100<<endl;
			break;
		}
	}
}