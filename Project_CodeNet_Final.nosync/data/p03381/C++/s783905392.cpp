#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int vals[200200];

int tmp[200200];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) scanf("%d", vals + i);
	for(int i = 0; i < N; ++i) tmp[i] = vals[i];
	sort(tmp, tmp + N);
	int id = N / 2 - 1;
	for(int i = 0; i < N; ++i){
		if(vals[i] < tmp[id + 1]) printf("%d\n", tmp[id + 1]);
		else printf("%d\n", tmp[id]);
	}
	return 0;
}
