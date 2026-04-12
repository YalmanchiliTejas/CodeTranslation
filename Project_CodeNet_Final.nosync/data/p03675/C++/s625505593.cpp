#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define FORR(i,a,n) for(int i=a;i>n;i--)
#define ri(x) scanf("%d",&x)
#define rii(x,y) ri(x), ri(y)
#define S second
#define F first
#define pb push_back
#define mp make_pair
#define db(x) printf("%d\n",x)
typedef long long ll;
int a[200000];
int main(){
	int n;
	ri(n);
	FOR(i,0,n)
		ri(a[i]);
	int l;
	FORR(i,n-1,-1){
		printf("%d ",a[i]);
		i--;
		l=i;
	}
	if(l==0){
		FOR(i,0,n){
			printf("%d ",a[i]);
			i++;
		}
	}
	else{
		FOR(i,1,n){
			printf("%d ",a[i]);
			i++;
		}
	}
	printf("\n");
	return 0;
}
