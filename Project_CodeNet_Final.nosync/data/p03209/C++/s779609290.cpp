#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>

const long INF = (1l << 30);
const long LINF = (1l << 60);

long n, x;
long thick[55];
long pate[55];

long cnt(long x, long cl){//0 < x <= thick[class]
    if(x == 0){
        return 0;
    }
    long res = 0;
    if(x == thick[cl]){
        return pate[cl];
    }
    x -= 1;
    if(x > thick[cl-1]){
        res += pate[cl-1];
        x -= thick[cl-1];
        if(x > 0){
            res += 1;
            x -= 1;
        }
    }
    res += cnt(x, cl-1);
    return res;
}

int main(){
    scanf("%ld%ld", &n, &x);
    thick[0] = 1;
    pate[0] = 1;
    for(int i = 1; i <= 50; i++){
        thick[i] = 2 * thick[i-1] + 3;
        pate[i] = 2 * pate[i-1] + 1;
        //printf("(%ld %ld %ld)\n", i, thick[i], pate[i]);
    }
    printf("%ld\n", cnt(x, n));
}
