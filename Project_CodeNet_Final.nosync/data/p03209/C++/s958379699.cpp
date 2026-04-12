#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long> fn(51, 1);
vector<long long> fp(51, 1);


long long dfs(long long level, long long x){
    if(level == 0){
        return 1;
    }
    
    if(x == 1){
        return 0;
    }
    else if(2 <= x and x <= 1 + fn[level-1]){
        return dfs(level-1, x-1);
    }
    else if(x == 2+ fn[level-1]){
        return fp[level-1] + 1;
    }
    else if(3+fn[level-1] <= x and x <= 2+2*fn[level-1]){
        return fp[level-1] + 1 + dfs(level-1, x-2-fn[level-1]);
    }
    else if(x == 3 + 2*fn[level-1]){
        return 2*fp[level-1] + 1;
    }
    return -1;

}

int main(){
    long long n, x;
    cin >> n >> x;

    for(long long i = 1; i <= 50; i++){
        fn[i] = 2*fn[i-1] + 3;
        fp[i] = 2*fp[i-1] + 1;
    }

    cout << dfs(n, x) << endl;
    return 0;
}