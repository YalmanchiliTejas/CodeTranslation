#include<cstdio>
#include<algorithm>
#include<set>
struct node{
	int x,y;
	bool operator<(node b)const{
		return x<b.x;
	}
}a[200100];
int n;
long long ans=0x3f3f3f3f3f3f3f3f;
std::multiset<int>A,B;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x<a[i].y)std::swap(a[i].x,a[i].y);
		A.insert(a[i].x),B.insert(a[i].y);
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		A.erase(A.find(a[i].x));
		B.insert(a[i].x);
		B.erase(B.find(a[i].y));
		A.insert(a[i].y);
	  	ans=std::min(ans,(long long)(*A.rbegin()-*A.begin())*(*B.rbegin()-*B.begin()));
	}
	printf("%lld\n",ans);
} 