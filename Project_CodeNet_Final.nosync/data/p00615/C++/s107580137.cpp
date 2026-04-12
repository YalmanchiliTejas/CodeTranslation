#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<time.h>
#include<cmath>
#include<queue>
using namespace std;
#define INF 100000000
typedef long long ll;
int m,n,tn[10001],tm[10001];
int min(int a,int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}
int max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int main(){
	while(1){
		int time=0,maxi=0;
		cin>>n>>m;
		if(n+m==0)break;
		for(int i=0;i<n;i++){
			cin>>tn[i];
		}
		tn[n]=INF;
		for(int i=0;i<m;i++){
			cin>>tm[i];
		}
		tm[m]=INF;
		int i=0,j=0;
		while(i<n||j<m){
			if(tn[i]<=tm[j]){
				maxi=max(maxi,tn[i]-time);
				time=tn[i];i++;
			}else{
				maxi=max(maxi,tm[j]-time);
				time=tm[j];j++;
			}
		}
		cout<<maxi<<endl;
	}
	return 0;
}	