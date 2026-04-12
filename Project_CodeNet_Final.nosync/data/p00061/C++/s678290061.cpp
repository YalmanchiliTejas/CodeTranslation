#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <cfloat>
using namespace std;
int main(){
	
	int a[101]={0};
	int s[31]={0};
	int x,y;
	char comma;
	
	while(cin>>x>>comma>>y,x!=0||y!=0){
		a[x]=y;
		s[y]=1;
	}
	int f;
	while(cin>>f){
		int c=1;
		for(int i=a[f]+1;i<31;i++){
			if(s[i]==1)
				c++;
		}
		cout<<c<<endl;
	}
	
	
 	
}