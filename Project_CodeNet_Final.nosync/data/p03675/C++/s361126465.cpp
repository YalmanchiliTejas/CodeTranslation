#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<cstdio>
#include<deque> 
using namespace std;
int main(){
int n;
scanf("%d",&n);
deque<int>Q;
for(int i=0;i<n;i++){
	int a;
	scanf("%d",&a);
	if(i%2==0){
		Q.push_back(a);
	}else{
		Q.push_front(a); 
	}
	}
	if(n%2==0){
		for(int i=0;i<n;i++)
		printf("%d%c",Q[i],i==n-1?'\n':' ');
	}else{
		for(int i=0;i<n;i++)
		printf("%d%c",Q[n-1-i],i==n-1?'\n':' ');
	}
	return 0;
}