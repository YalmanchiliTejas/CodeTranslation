#include <bits/stdc++.h>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int N;
int A[200010],B[200010];

int main(){
	cin >> N;
	for(int i = 1; i <= N; ++i){
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B + 1,B + N + 1);
	int mid = B[N / 2];
	for(int i = 1; i <= N; ++i){
		if(A[i] <= mid) printf("%d\n",B[N / 2 + 1]);
		else printf("%d\n",mid);
	}

	return 0;
}