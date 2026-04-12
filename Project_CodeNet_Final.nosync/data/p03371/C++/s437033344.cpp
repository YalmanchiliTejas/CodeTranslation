#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int A,B,C,X,Y;
	int ans=0;
	int temp;

	scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);

	if(2*C<A+B){
		temp = min(X,Y);
		ans += C*2*temp;
		X -= temp;
		Y -= temp;
		if(X!=0){
			if(2*C<A){
				ans += C*2*X;
			}else{
				ans += A*X;
			}
		}else{
			if(2*C<B){
				ans += C*2*Y;
			}else{
				ans += B*Y;
			}
		}
	}else{
		ans = (A*X) + (B*Y);
	}
	printf("%d",ans);

	return 0;
}