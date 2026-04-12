#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

long long vals[55];
int N;
long long all;

void print(){
	for(int i = 0; i < N; ++i) printf("%lld ", vals[i]);
	printf("\n");
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) scanf("%lld", vals + i);
}

void simulate(int id, long long x){
	vals[id] -= x * (N + 1);
	for(int i = 0; i < N; ++i){
		vals[i] += x;
	}
}

long long c[55];

long long solve(){
	long long ans = 0;
	all = 0;
	for(int i = 0; i < N; ++i) all += vals[i];
	for(int i = 0; i < N; ++i){
		long long tmp = vals[i] + all - N * N - N;
	//	printf("%lld\n", tmp);
		tmp /= (N + 1);
		if(tmp < 0) tmp = 0;
		c[i] = tmp;
//		simulate(i, tmp);
//		ans += tmp;
	}
	for(int i = 0; i < N; ++i){
		simulate(i, c[i]);
		ans += c[i];
	}
	while(true){
		int id = -1;
		for(int i = 0; i < N; ++i){
			if(vals[i] >= N){
				id = i;
				break;
			}
		}
		if(id == -1) break;
		simulate(id, 1);
		ans++;
	}
	return ans;
}

int main(){
	input();
	long long ans = solve();
	printf("%lld\n", ans);
	return 0;
}
