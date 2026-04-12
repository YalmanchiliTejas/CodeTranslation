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

vector<int> V[9];
bool b[9];
int N,M;
int ans;

void dfs(int q , int d){
	if(d == N){
		++ans;
		return;
	}
	repv(int,it,V[q]){
		if(b[*it]) continue;
		b[*it] = 1;
		dfs(*it,d+1);
		b[*it] = 0;
	}
}

int main(){
	scanf("%d%d" , &N , &M);
	repp(i,0,M){
		int a,b;
		scanf("%d%d" , &a , &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	b[1] = 1;
	dfs(1,1);
	printf("%d\n" , ans);
	return 0;
}
