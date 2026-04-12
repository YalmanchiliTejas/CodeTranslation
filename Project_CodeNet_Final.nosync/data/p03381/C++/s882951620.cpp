#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define maxn 200000+5

using namespace std;

struct Data{
	int val,pos;
	bool operator <(const Data &T)const{
		return val<T.val;
	}
}a[maxn];

int ans[maxn],ori[maxn];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		ori[i]=a[i].val;
		a[i].pos=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans[a[i].pos]=n/2;
		if(ans[a[i].pos]>=i) ans[a[i].pos]++;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[ans[i]].val);	
	}
	return 0;
}