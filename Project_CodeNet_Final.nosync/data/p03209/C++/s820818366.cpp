#include <iostream>
#include <vector>
using namespace std;

long long int countP(vector<long long int>& num_level, vector<long long int>& pnum, int level, long long int x){
    long long int ans = 0;
    if(num_level[level] == x){
        ans = pnum[level];
    }else{
        if(x-num_level[level-1]-2 > 0){
            ans = pnum[level-1];
            ans += 1;
            ans += countP(num_level, pnum, level-1, x-num_level[level-1]-2);
        }else if(x-num_level[level-1]-2 == 0){
            ans = pnum[level-1];
            ans += 1;
        }else if(x-num_level[level-1]-1 == 0){
            ans = pnum[level-1];
        }else if(x-1 > 0){
            ans = countP(num_level, pnum, level-1, x-1);
        }else{
            if(level == 0) ans = 1;
            else ans = 0;
        }
    }
    return ans;
}

int main(){
    long long int n, x;
    cin >> n >> x;
    vector<long long int> num_level(n+1);
    vector<long long int> pnum(n+1);
    num_level[0] = 1;
    pnum[0] = 1;
    for(int i = 1; i <= n; i++){
        num_level[i] = 3+2*num_level[i-1];
        pnum[i] = 1+2*pnum[i-1];
    }

    cout << countP(num_level, pnum, n, x);
    return 0;
}