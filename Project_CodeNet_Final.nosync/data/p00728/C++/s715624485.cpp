#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n),n){
		vector < int > vi;
		for(int i = 0; i < n; i++){
			int tmp;
			scanf("%d",&tmp);
			vi.push_back(tmp);
		}
		sort(vi.begin(),vi.end());
		double ave = 0.0;
		for(int i = 1; i < n-1 ;i++){
			ave += vi[i];
		}
		printf("%.0lf\n",floor(ave/(n-2)));
	}
	return 0;
}