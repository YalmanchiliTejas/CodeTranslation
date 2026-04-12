/*
请问你们见到过我家梨花么？
非常可爱，简直是小天使！
不不不，没失踪也没怎么样，只是觉得你们都该看一下~~ 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end() 
#define ayacin ios::sync_with_stdio(false);
#define yukari (~0uLL>>1LL) 
#define yukari2 (~0u>>1) 
#define M_PI12 3.141592653
#define Parsee long double
#define reimu iterator 
#define mokou __builtin_popcount
#define __sum accumulate
#define rep(i,a,b) for(i=a;i<=b;i++)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define ls rt<<1
#define rs rt<<1|1 
#define eps 1e-10  
#define zero(a) fabs(a)<eps  
#define x first
#define y second
#define read(a) a=in<int>()
using namespace std;
const int MAXN=1e6+6;
//template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
char a[55][55];
int m,n;
void cover(int x,int y){
	if(x>m||y>n) return ;
	a[x][y]='.';
	if(a[x+1][y]=='#'){
		cover(x+1,y);
		return ;
	}
	if(a[x][y+1]=='#'){
		cover(x,y+1);
		return ;
	}
	return ;
}
int main(){
	int i,j,k,v;
	while(cin>>m>>n){
		rep(i,0,50) rep(j,0,50) a[i][j]='.';
	rep(i,1,m){
		rep(j,1,n) cin>>a[i][j];
	}
	cover(1,1);
	rep(i,1,m){
		rep(j,1,n){
			if(a[i][j]!='.'){
				puts("Impossible");
				goto l;
			}
		}
	}
	puts("Possible");
	l:; 
	}
}






