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

int H , W;
bool b[10][10];

int main(){
	scanf("%d%d" , &H , &W);
	repp(i,0,H){
		repp(j,0,W){
			char c;
			scanf(" %c" , &c);
			b[i][j] = c == '#';
		}
	}
	bool ans = b[0][0];
	int x = 0;
	int y = 0;
	b[0][0] = 0;
	while(x + 1 < H || y + 1 < W){
		if(b[x+1][y]){
			++x;
		} else if(b[x][y+1]){
			++y;
		} else {
			ans = 0;
			break;
		}
		b[x][y] = 0;
	}
	repp(i,0,H){
		repp(j,0,W){
			if(b[i][j]) ans = 0;
		}
	}
	printf("%s\n" , ans ? "Possible" : "Impossible");
	return 0;
}
