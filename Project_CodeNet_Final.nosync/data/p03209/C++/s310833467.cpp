#include<iostream>
#include<cmath>
using namespace std;
long long all_patti[51] = {};


long long solve(long long L, long long x){
    if(x <= 0){
        return 0;
    }
    if(L == 0){
        return 1;
    }
    long long all = pow(2LL, L + 2) - 3;
    if(x >= all && all_patti[L] != 0){
        return all_patti[L];
    }

    
    long long ans = 0;
    if(x > all / 2){
        // mid patti
        ans += 1;
    }
    ans += solve(L - 1, x - 1);
    ans += solve(L - 1, x - all/2 - 1);
    if(x >= all){
        all_patti[L] = ans;
    }
    return ans;

}

int main(){
    long long N, X;
    cin >> N >> X;
    cout << solve(N, X) << endl;
}
