#include <cstdio>

using namespace std ;
#define maxn 10
typedef long long ll ;

int map[maxn][maxn] ;
int n,m ;
ll ans ;
int vis[maxn] ;

bool check() {
	for(int i=1 ; i<=n; i++ )
		if(!vis[i]) return false ;
	return true ;
}

void dfs(int a) {
	vis[a] = 1 ;
	if(check()) {
		ans ++ ;
		vis[a] = 0 ;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(map[a][i]) {
			if(!vis[i])
				dfs(i) ;
		}
	}
	vis[a] = 0 ;
}


int main(void){

	scanf("%d %d",&n,&m ) ;
	for(int i=0; i<m; i++ ) {
		int a, b ;
		scanf("%d%d",&a,&b) ;
		map[a][b] = 1 ;
		map[b][a] = 1 ;
	}
	dfs(1) ;

	printf("%lld\n",ans) ;
	return 0 ;
}