#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int,long long int> P;

int N;
P pr[200001];

int main(){
	scanf("%d",&N);
	pr[0].first = 0;
	pr[0].second = 0;
	for(int i = 1; i <= N; i++){
		int tmp;
		scanf("%d",&tmp);
		pr[i].first = pr[i-1].first + tmp;
		pr[i].second = i;		
	}
	sort(pr,pr+N+1);
/*
	for(int i = 0; i <= N; i++){
		printf("%d %d\n",pr[i].first,pr[i].second);
	}
*/
	long long int pre = pr[0].first;
	long long int num = pr[0].second;
	long long int ans = 0;
	for(int i = 1; i <= N; i++){
		if(pre == pr[i].first){
			ans = max(ans,pr[i].second - num);
		}
		else{
			pre = pr[i].first;
			num = pr[i].second;
		}
	}
	printf("%lld\n",ans);

	return 0;
}

