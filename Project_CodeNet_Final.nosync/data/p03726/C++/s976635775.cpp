#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
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

const int MC = 100010;
int N;
vector<int> V[MC];
int p[MC];
int d[MC];
queue<int> Q;
int c;

int halt(){
	printf("First\n");
	return 0;
}

int main(){
	scanf("%d" , &N);
	repp(i,1,N){
		int a,b;
		scanf("%d%d" , &a , &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	repp(i,1,N+1){
		p[i] = -1;
		d[i] = (int)V[i].size();
		if(d[i] == 1) Q.push(i);
	}
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		p[x] = 0;
		++c;
		for(auto u : V[x]){
			if(p[u] < 0){
				--d[u];
				if(d[u] == 1) Q.push(u);
			} else if(p[u] == 0){
				++p[x];
			}
		}
		if(p[x] > 1) return halt();
		if(c == N && p[x] != 1) return halt();
	}
	printf("Second\n");
	return 0;
}
