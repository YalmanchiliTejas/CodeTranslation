#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <regex> //正規表現
#include <map>
#include <set>
#include <cassert> //assart
using namespace std;
#define ll long long int
#define FOR(i,min,max) for(int i=(min);i<(max);i++)
#define FOReq(i,min,max) for(int i=(min);i<=(max);i++)
#define FORREV(i,max,min) for(int i=(max)-1;i>=(min);i--)
const int  MOD=1e9+7;
const int  INF=2000000000;
const int INF2=  10000000;
const double  Micro=1e-5;

int UnUsedVariable(){
    if(INF || Micro || MOD || INF2){;}
    return 0;
}

#define pf printf
#define sf scanf
#define inarray(array,min,max) FOR(i,min,max){cin>>array[i];}
#define inarrayW(arrayA,arrayB,min,max) FOR(i,min,max){cin>>arrayA[i]>>arrayB[i];}
inline int isEven(int x){return x%2==0;}
inline int isOdd (int x){return x%2==1;}
#define br printf("\n");
#define OutputAndReturn0(x) {cout<<(x)<<endl;return 0;}

int printintN(int array[],const int num){
    for(int i=0;i<num;i++){printf("%d ",array[i]);}
    br;
    return 0;
}


//#define int long long int

/*
 1.困った時こそ冷静に問題文を見直す！制約条件を見ろ！乱択アルゴリズムとかO(N^3)とか！
 2.一度に大量のことをやろうとしない。デバッグしやすいように細かく！
 3.プログラミングは半分数学だし、もう半分は数学ではない！
 4.できない問題はできない！！！！！
 */

int experiment(){
    int N;
    cin>>N;
    int partlymax=0;
    int H[N];
    int ans=0;
    FOR(i, 0, N){
        cin>>H[i];
        if(H[i]>=partlymax)ans++;
        partlymax=max(partlymax,H[i]);
    }
    OutputAndReturn0(ans);
    return 0;
}
signed main(){
    assert(1);
    experiment();
    return 0;
}
