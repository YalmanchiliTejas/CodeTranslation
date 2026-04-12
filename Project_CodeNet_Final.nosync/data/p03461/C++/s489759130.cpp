#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<ctime>
using namespace std;
typedef long long ll;
const int N = 210;
ll read() {
	ll x = 0,f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1; c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0'; c = getchar();
	}
	return x * f;
}
int d[N][N],f[N][N],A,B,X[N],Y[N];
int main() {
	A = read(),B = read();
	
	for(int i = 1;i <= A;++i)
		for(int j = 1;j <= B;++j)
			d[i][j] = read();
	
	
	for(int i = 0;i <= 100;++i)
		for(int j = 0;j <= 100;++j)
			for(int x = 1;x <= A;++x)
				for(int y = 1;y <= B;++y)
					f[i][j] = max(f[i][j],d[x][y] - i * x - j * y);
	
	for(int x = 1;x <= A;++x) {
		for(int y = 1;y <= B;++y) {
			int tmp = 1e9;
			for(int i = 0;i <= 100;++i) {
				for(int j = 0;j <= 100;++j) {
					tmp = min(tmp,f[i][j] + i * x + j * y);					
				}
			}
			if(tmp != d[x][y]) return puts("Impossible"),0;
		}
	}
	
	
	
    puts("Possible");
    puts("202 10401");
    for(int i = 1 ; i <= 100 ; ++i)
    printf("%d %d X\n" , i , i + 1);
    for(int i = 102 ; i < 202 ; ++i)
    printf("%d %d Y\n" , i , i + 1);
    for(int i = 0 ; i <= 100 ; ++i)
    for(int j = 0 ; j <= 100 ; ++j)
        printf("%d %d %d\n" , 1 + i , 202 - j , f[i][j]);
    puts("1 202");

	return 0;
}
