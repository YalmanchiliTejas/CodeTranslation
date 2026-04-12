#include <cstdio>
#include <algorithm>

using namespace std;




int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n == 0) break;
		int ma,mi,sum = 0,point;
		for(int i = 0;i < n;i++){
			scanf("%d",&point);
			sum += point;
			if(i == 0){
				ma = point;
				mi = point;
			}
			ma = max(ma,point);
			mi = min(mi,point);
		}
		printf("%d\n",(sum-ma-mi)/(n-2));
		
	}
}
