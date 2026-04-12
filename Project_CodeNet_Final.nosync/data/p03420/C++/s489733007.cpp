#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;



int main(){
	int N;
	int K;
	scanf("%d %d",&N,&K);

	long long ans = 0;

	if(K==0){
		long long tmp = N;
		tmp*= tmp;
		printf("%lld\n", tmp);
		return 0;
	}

	for(int b=K+1;b<=N;b++){
		long long tmp = (N+(b-N%b))/b;
		tmp *= b-K;
		if(N%b<K) tmp -= b-K;
		else tmp -= b-1-(N%b);
		ans += tmp;
		//printf("%lld\n",tmp);
	}

	printf("%lld\n", ans);

	return 0;
}
