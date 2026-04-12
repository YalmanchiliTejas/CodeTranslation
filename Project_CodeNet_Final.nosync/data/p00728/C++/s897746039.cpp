#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	for(int n;scanf("%d",&n),n;){
		int maxi=0,mini=1000,sum=0;
		rep(i,n){
			int a; scanf("%d",&a);
			sum+=a;
			if(maxi<a) maxi=a;
			if(mini>a) mini=a;
		}
		printf("%d\n",(sum-maxi-mini)/(n-2));
	}

	return 0;
}