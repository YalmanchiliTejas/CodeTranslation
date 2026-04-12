#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

LL N;
LL a[55];
LL s;

int main(){
	scanf("%lld" , &N);
	repp(i,0,N){
		scanf("%lld" , a + i);
		s += a[i];
	}
	repm(r,N*(N-1),-1){
		LL K = s-r;
		if(K < 0) continue;
		LL b = 0;
		repp(i,0,N){
			LL p = (a[i]+K)%(N+1);
			if(p == N) b = -1234567;
			b += p;
		}
		if(b == r){
			printf("%lld\n" , K);
			break;
		}
	}
	return 0;
}