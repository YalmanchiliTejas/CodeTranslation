#define de puts("#")
#define bug(x) cout<<#x<<" : "<<x<<endl
#define cha1 printf("L : %d,R : %d,x : %d,l : %d,r : %d,rt : %d\n",L,R,x,l,r,rt)
#define cha2 printf("L : %d,R : %d,l : %d,r : %d,rt : %d\n",L,R,l,r,rt)
#define cha3 printf("pos : %d,x : %d,l : %d,r : %d,rt : %d\n",pos,x,l,r,rt)
#define lcha1 printf("L : %lld,R : %lld,x : %lld,l : %lld,r : %lld,rt : %lld\n",L,R,x,l,r,rt)
#define lcha2 printf("L : %lld,R : %lld,l : %lld,r : %lld,rt : %lld\n",L,R,l,r,rt)
#define lcha3 printf("pos : %lld,x : %lld,l : %lld,r : %lld,rt : %lld\n",pos,x,l,r,rt)
#define huge(n,m,a) for(int i=1; i<=n; i++) {for(int j=1; j<=m; j++)printf("%d ",a[i][j]);puts("");}puts("")
#define lhuge(n,m,a) for(int i=1; i<=n; i++) {for(int j=1; j<=m; j++)printf("%lld ",a[i][j]);puts("");}puts("")
#define lowbit(x) (x&(-x))
#define IN freopen("in.txt","r",stdin)
#define OUT1 freopen("out1.txt","w",stdout)
#define OUT2 freopen("out2.txt","w",stdout)
#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
multiset<int>q;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		multiset<int>::iterator it=q.lower_bound(a[i]);
		if(it==q.begin())q.insert(a[i]);
		else{
			it--;
			q.erase(it);
			q.insert(a[i]);
		}
	}
	printf("%d\n",q.size());
	return 0;
}