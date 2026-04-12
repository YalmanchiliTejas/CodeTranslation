#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define mod 1e9+7
#define ll long long int
#define epsilon 1e-7

ll min(ll x, ll y){
    if(x<y)return x;
    return y;
}
int a[8];
int b[8];
int p[8][8];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int count = 0;
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            p[0][0] = 0;
        }
    }
    for(int i = 0;i < m;i++){
        int c, d;
        scanf("%d %d", &c, &d);
        c--;
        d--;
        p[c][d] = 1;
        p[d][c] = 1;
    }
    for(int i = 0;i < 8;i++){
        a[i] = i;
    }
    do {
        int flag = 1;
        for(int i = 0;i < n-1;i++){
            if(!p[a[i]][a[i+1]]){
                flag = 0;
                break;
            }
        }
        if(flag)count++;
    }while(next_permutation(a + 1, a + n));
    printf("%d\n", count);
    return 0;
}