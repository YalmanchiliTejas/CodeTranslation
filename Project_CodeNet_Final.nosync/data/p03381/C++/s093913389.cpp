#include<cstdio>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("C.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 2e5 + 100;
struct Node{
	int d,i;
	Node(int d,int i){
		this->d = d, this->i = 0;
	}
	Node(){
		this->d = 0,this->i = 0;
	}
}A[N];
int ans[N];
bool operator < (Node & a,Node & b){
	if( a.d == b.d )return a.i < b.i;
	return a.d < b.d;
}
map<int ,int >pos;
void inp(){
	int n;scanf("%d",&n);
	int tmp;
	for(int i = 1;i<=n;i++){
		scanf("%d", &tmp);
		A[i].i = i;
		A[i].d = tmp;
	}
	sort(A + 1, A + n + 1);
	for(int i = 1;i<=n;i++){
		pos[ A[i].i ] = i;
	}
	int mval= A[n / 2].d;
	int mpos = n/2;
//	for(int i = 1;i<=n;i++)printf("(%d %d)", A[i].d, A[i].i );
//			putchar('\n');
	for(int i = 1;i<=n;i++){
		int xi = A[i].i ;
		int xival = A[i].d;
		if( xival <= mval ){
				ans[ xi ] = A[mpos + 1].d;
		}
		else if ( xival > mval ){
			ans[xi] = A[ mpos ].d;
		}
	}
	for(int i = 1;i<=n;i++)printf("%d\n", ans[i]);
}
//C.cc by xsthunder at Sat Apr 14 20:12:05 2018
