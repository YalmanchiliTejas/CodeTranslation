#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

#define YES(condition) if(condition){ cout << "YES" << endl; }else{ cout << "NO" << endl; }
#define Yes(condition) if(condition){ cout << "Yes" << endl; }else{ cout << "No" << endl; }
#define POSS(condition) if(condition){ cout << "POSSIBLE" << endl; }else{ cout << "IMPOSSIBLE" << endl; }
#define Poss(condition) if(condition){ cout << "Possible" << endl; }else{ cout << "Impossible" << endl; }
long power(long base, long exponent, long mod){ if(exponent % 2){ return power(base, exponent - 1, mod) * base % mod; }else if(exponent){ long root_ans = power(base, exponent / 2, mod); return root_ans * root_ans % mod; }else{ return 1; }}

int main(){
    int N;
    cin >> N;
    int nums[N];
    int nums_sorted[N];
    for(int i = 0; i < N; i++){
        cin >> nums[i];
        nums_sorted[i] = nums[i];
    }
    sort(nums_sorted, nums_sorted + N);
    for(int i = 0; i < N; i++){
        if(nums[i] >= nums_sorted[N / 2]){
            cout << nums_sorted[(N - 1) / 2] << endl;
        }else{
            cout << nums_sorted[N / 2] << endl;
        }
    }
}

