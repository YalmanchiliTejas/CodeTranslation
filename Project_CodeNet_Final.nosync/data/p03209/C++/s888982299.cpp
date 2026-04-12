#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <string>

#define REP(i, n) for (int i=0;i<(n);i++)
#define FOR(i, a, b) for (int i=(a);i<(b);i++)

using namespace std;


long long int layer_num[51];
long long int p_num[51];
long long int b_num[51];

long long int depth(int L, long long int remain)
{
    if(L==0) {
        return 1;
    }
    if(remain==0) {
        return 0;
    } else if(remain==1) {
        return 0;
    } else if(1<remain && remain<=layer_num[L-1]+1) {
        return depth(L-1, remain-1);
    } else if(remain==layer_num[L-1]+2) {
        return depth(L-1, remain-2) + 1;
    } else if(layer_num[L-1]+2<remain && remain<=layer_num[L-1]*2+2) {
        return depth(L-1, layer_num[L-1]) + 1 + depth(L-1, remain-2-layer_num[L-1]);
    } else if(remain==layer_num[L-1]*2+3) {
        return depth(L-1, layer_num[L-1])*2 + 1;
    } else {
        cout << "error!" <<endl;
    }
    return 0;
}


int main()
{
    int N;
    long long int X;
    scanf("%d %lld", &N, &X);
    layer_num[0] = 1;
    p_num[0] = 1;
    b_num[0] = 0;
    FOR(i, 1, N+1) {
        layer_num[i] = layer_num[i-1]*2 + 3;
        //p_num[i] = p_num[i-1]*2 + 1;
        //b_num[i] = b_num[i-1]*2 + 2;
        //cout << layer_num[i] << endl;
        //cout << p_num[i] << endl;
        //cout << b_num[i] << endl;
    }
    cout << depth(N, X) << endl;


    return 0;
}
