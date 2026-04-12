#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define Fst first
#define Snd second
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repv(t,it,v) for(vector<t>::iterator it = v.begin() ; it != v.end() ; ++it)

typedef long long LL;

LL K;
char s[10] = "FESTIVA";

int main(){
	scanf("%lld" , &K);
	printf("%s" , s);
	if(K % 2 == 1) printf("L");
	K /= 2;
	repm(i,6,0){
		if(K == 0) break;
		printf("%s" , s + i);
		if(K % 2 == 1) printf("L");
		K /= 2;
	}
	if(K > 0){
		printf("%s" , s);
		if(K % 2 == 1) printf("L");
		K /= 2;
	}
	repp(i,0,7){
		repp(j,1,8){
			if(K == 0) break;
			repm(t,1<<j,0){
				printf("%c" , s[i]);
			}
			printf("%s" , s + i + 1);
			if(K % 2 == 1) printf("L");
			K /= 2;
		}
	}
	repm(i,K*2,0){
		printf("L");
	}
	printf("\n");
	return 0;
}
