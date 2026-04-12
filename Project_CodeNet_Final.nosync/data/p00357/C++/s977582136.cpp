
//y17-6
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define segment_size 65536
#define ROOP() while(true)

int N;
int d[300002];
int dp_l[300002];
int dp_r[300002];

bool move_l(int now){
    if(dp_l[now] == 0) return false;
    if(dp_l[now] == 1) return true;

    if(now == N-1) return true;
    if(now > N-1) return false;

    for(int i=1; i<=d[now]/10; i++){
        if(move_l(now+i)){
            dp_l[now] = 1;
            return true;
        }
    }
    dp_l[now] = 0;
    return false;
}

bool move_r(int now){
    if(dp_r[now] == 0) return false;
    if(dp_r[now] == 1) return true;

    if(now == 0) return true;
    if(now < 0) return false;

    for(int i=1; i<=d[now]/10; i++){
        if(move_r(now-i)){
            dp_r[now] = 1;
            return true;
        }
    }
    dp_r[now] = 0;
    return false;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> d[i];
        dp_l[i] = -1;
        dp_r[i] = -1;
        if(d[i] < 10){
            dp_l[i] = 0;
            dp_r[i] = 0;
        }
    }
    
    if(!move_l(0)){
        cout << "no" << endl;
        return 0;
    }
    if(!move_r(N-1)){
        cout << "no" << endl;
        return 0;
    }

    cout << "yes" << endl;
}

