#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	for(int n;scanf("%d",&n),n;){
		int sum=0,mx=-1,mn=1001;
		for(int i=0;i<n;i++){
			int a;	scanf("%d",&a);
			sum+=a;
			mx=max(mx,a);
			mn=min(mn,a);
		}
		printf("%d\n",(sum-mx-mn)/(n-2));
	}
	return 0;
}