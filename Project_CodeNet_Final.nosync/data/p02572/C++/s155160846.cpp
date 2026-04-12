#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){

    long long N;
    vector<long long> arr;
    cin >> N;
    long long M = 1000000007;
    long long sum =0;
    
    for(int i =0; i < N; ++i){
        long long tmp;
        cin >> tmp;
        //tmp %= M;
        sum += tmp;
        //sum %= M;
        arr.push_back(tmp);
    }
    long long ans = 0;
    for(int i=0; i < N-1; ++i){
        long long A = arr[i];
        sum -= A;
        //sum %= M;
        ans += (sum%M)*A%M;
        ans %= M;
        
    }
    //ans %=M;

    cout << ans << endl;

    return 0;
}