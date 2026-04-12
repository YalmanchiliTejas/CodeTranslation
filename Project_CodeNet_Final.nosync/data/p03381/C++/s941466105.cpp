#include <cstdio>
#include <algorithm>
using namespace std;
const int N=200010;
int n;
int a[N],b[N];
void readData(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
}
void solve(){
	sort(b+1,b+1+n);
	int x=b[n>>1],y=b[(n>>1)+1];
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]<=x?y:x);
}
int main(){
	readData();
	solve();
	return 0;
}
