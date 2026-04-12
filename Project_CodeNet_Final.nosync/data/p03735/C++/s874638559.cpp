#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
	int x,y;
}a[210000];
int n;
int prenn[210000],prenx[210000],prexn[210000],prexx[210000],sufnn[210000],sufnx[210000],sufxn[210000],sufxx[210000];

typedef long long ll;

ll ans=1ll<<60;

int cmp(Node x,Node y){
	if(x.x!=y.x)return x.x<y.x;
	return x.y<y.y;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	}sort(a+1,a+n+1,cmp);
	prenn[0]=1<<30;prenx[0]=0;
	sufnn[n+1]=1<<30;prenx[n+1]=0;
	prexn[0]=1<<30;prexx[0]=0;
	sufxn[n+1]=1<<30;sufxx[n+1]=0;
	for(int i=1;i<=n;i++){
		prenn[i]=min(prenn[i-1],a[i].x);
		prenx[i]=max(prenx[i-1],a[i].x);
		prexn[i]=min(prexn[i-1],a[i].y);
		prexx[i]=max(prexx[i-1],a[i].y);
	}for(int i=n;i;i--){
		sufnn[i]=min(sufnn[i+1],a[i].x);
		sufnx[i]=max(sufnx[i+1],a[i].x);
		sufxn[i]=min(sufxn[i+1],a[i].y);
		sufxx[i]=max(sufxx[i+1],a[i].y);
	}ans=min(ans,(ll)(prenx[n]-prenn[n])*(prexx[n]-prexn[n]));
	for(int i=1;i<=n-1;i++){
		ans=min(ans,(ll)(max(prexx[i],sufnx[i+1])-min(prexn[i],sufnn[i+1]))*(max(prenx[i],sufxx[i+1])-min(prenn[i],sufxn[i+1])));
	}printf("%lld\n",ans);
	return 0;
}