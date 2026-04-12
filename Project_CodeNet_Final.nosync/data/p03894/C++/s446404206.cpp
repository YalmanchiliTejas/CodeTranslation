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

int N,Q;
int b[100010];

int main(){
	scanf("%d%d" , &N, &Q);
	b[1] = 1;
	b[2] = 1;
	int x = 1;
	repp(i,0,Q){
		int A,B;
		scanf("%d%d" , &A , &B);
		swap(b[A] , b[B]);
		if(A == x){
			x = B;
		} else if(B == x){
			x = A;
		}
		b[x-1] = b[x+1] = 1;
	}
	int ans = 0;
	repp(i,1,N+1){
		if(b[i] > 0) ++ans;
	}
	printf("%d\n" , ans);
	return 0;
}
