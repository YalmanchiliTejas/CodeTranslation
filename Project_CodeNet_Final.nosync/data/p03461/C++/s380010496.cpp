#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<cmath>
#include<random>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c) && c != EOF){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    if(c == EOF)
        exit(0);
    while(isdigit(c)){
	a = a * 10 + c - 48;
        c = getchar();
    }
    return f ? -a : a;
}

int d[12][12] , f[107][107];

signed main(){
    int A = read() , B = read();
    for(int i = 1 ; i <= A ; ++i)
	for(int j = 1 ; j <= B ; ++j)
	    d[i][j] = read();
    for(int i = 0 ; i <= 100 ; ++i)
	for(int j = 0 ; j <= 100 ; ++j)
	    for(int p = 1 ; p <= A ; ++p)
		for(int q = 1 ; q <= B ; ++q)
		    f[i][j] = max(f[i][j] , d[p][q] - i * p - j * q);
    for(int i = 1 ; i <= A ; ++i)
	for(int j = 1 ; j <= B ; ++j){
	    int minN = 1e9;
	    for(int p = 0 ; p <= 100 ; ++p)
		for(int q = 0 ; q <= 100 ; ++q)
		    minN = min(minN , f[p][q] + p * i + q * j);
	    if(minN != d[i][j]){
		puts("Impossible");
		return 0;
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
