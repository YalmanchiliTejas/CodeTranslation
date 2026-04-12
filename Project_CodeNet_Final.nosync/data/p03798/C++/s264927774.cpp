#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

int N;
string S;

bool check(int x,int y){
	int a[100010]={};
	a[0]=x; a[1]=y;
	reg(i,1,N){
		int c=0;
		if(S[i-1]=='o')c++;
		if(a[i-1]==1)c++;//S
		if(a[i]==1)c++;//S
		if(c%2==0)a[i+1]=2;//W
		if(c%2==1)a[i+1]=1;//S
	}
	if(a[N]==a[0] && a[N+1]==a[1]){
		reg(i,1,N){
			if(a[i]==1){
				printf("S");
			}else{
				printf("W");
			}
		}
		printf("\n");
		return true;
	}
	return false;
}

int main(void){
	scanf("%d",&N);
	cin>>S;
	if(check(1,1))return 0;
	if(check(1,2))return 0;
	if(check(2,1))return 0;
	if(check(2,2))return 0;
	printf("-1\n");
	return 0;
}