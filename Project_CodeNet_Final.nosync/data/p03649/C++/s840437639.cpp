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
LL K;

int main(){
	scanf("%lld" , &N);
	repp(i,0,N){
		scanf("%lld" , a + i);
		K += a[i];
	}
	repm(i,N*(N-1),-1){
		LL z = K-i;
		if(z < 0) continue;
		LL b = 0;
		LL c = 0;
		repp(j,0,N){
			LL p = (a[j]+z)/(N+1);
			LL q = a[j]+z-(N+1)*p;
			if(q == N) b = -1234567;
			b += q;
			c += p;
		}
		if(b == i && c == z){
			printf("%lld\n" , z);
			break;
		}
	}
	return 0;
}
