#include<cstdio>
#include<algorithm>
#include<cstring>
#define lowbit(x) x&-x
#define M 100005
using namespace std;
void check_max(int &x,int y){if(x<y)x=y;}
int A[M],B[M];
struct Bin{
	int num[M];
	void clear(){memset(num,0,sizeof(num));}
	void Add(int x,int d){
		x++;
		while(x){
			check_max(num[x],d);
			x-=lowbit(x);
		}
	}
	int sum(int x){
		x++;
		int res=0;
		while(x<M){
			check_max(res,num[x]);
			x+=lowbit(x);
		}
		return res;
	}
}C;
int main(){
	C.clear();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);
	int id=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;i++)A[i]=lower_bound(B+1,B+id+1,A[i])-B;
	int mx=0;
	for(int i=1;i<=n;i++){
		int dp=C.sum(A[i])+1;
		C.Add(A[i],dp);
		check_max(mx,dp);
	}
	printf("%d\n",mx);
	return 0;
}