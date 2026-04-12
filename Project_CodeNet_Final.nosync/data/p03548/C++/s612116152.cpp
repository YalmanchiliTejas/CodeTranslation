#include <bits/stdc++.h>

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
#define BIT(bit,a,n) for (int bit = a;bit < (1<<n);bit++) // {0, 1, ..., n-1} の部分集合の全探索 // n番目のフラグが立っている状態は (1<<n)

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

#define MAX_N (int)2e5+20

typedef long long ll;
using namespace std;

int x,y,z;
int main() {
    scanf("%d%d%d",&x,&y,&z);
    int ans = (x-z)/(y+z);
    pout(ans);
    return 0;
}