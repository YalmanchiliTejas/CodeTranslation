#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#include<set>
using namespace std;
int n,a[110000],ans;
multiset<int> q;
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n){
		auto it=q.lower_bound(a[i]);
		if (it==q.begin()){
			ans++;
			q.insert(a[i]);
		}else{
			it--;
			q.erase(it);//erase(*it)
			q.insert(a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}