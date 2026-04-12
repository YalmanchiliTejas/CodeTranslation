#include <bits/stdc++.h>
using namespace std ;

struct edge{
	int u , v , w ;
};

vector<edge> E ;
int n , p[100010] ;

bool operator < (edge A , edge B){
	return A.w < B.w ;
} 

int Find(int x)
{
	if(p[x] == x)return x ;
	return p[x] = Find(p[x]) ;
}

void Union(int x , int y){
	p[Find(x)] = p[y] ;
}

long long int kruskal()
{
	long long int ret = 0 ;

	for(int i = 0 ; i <= n ; i++)p[i] = i ;

	for (edge x : E){
		if(Find(x.u) == Find(x.v))continue ;

		Union(x.u , x.v) ;
		ret += (long long)x.w ;
	}
	return ret ;
}

int main(int argc, char const *argv[])
{
	pair<int , int> x[100010] , y[100010] ;

	scanf("%d" , &n) ;

	for(int i = 0 ; i < n ; i++){
		scanf("%d %d" , &x[i].first , &y[i].first) ;
		x[i].second = y[i].second = i+1 ; 
	}

	sort(x , x+n) ;
	sort(y , y+n) ;

	edge a ;

	for (int i = 0 ; i < n-1 ; i++){
		a.u = x[i].second ;
		a.v = x[i+1].second ;
		a.w = x[i+1].first-x[i].first ;
		E.push_back(a) ;
	}

	for (int i = 0 ; i < n-1 ; i++){
		a.u = y[i].second ;
		a.v = y[i+1].second ;
		a.w = y[i+1].first-y[i].first ;
		E.push_back(a) ;
	}

	sort(E.begin(), E.end()) ;

	printf("%lld\n", kruskal());

	return 0;
}
