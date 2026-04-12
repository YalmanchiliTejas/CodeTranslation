#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
#include <utility>
#include <map>
#include <set>
#include <numeric>
using namespace std;

int main(){
    long long int n, a;
    vector<long long int> v;
    cin >> n;
    
    long long int i;
    
    for(i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    long long int ans;
    long long int sum1 = 0;
    long long int sum2 = 0;
    long long int minus = 0;
    long long int plus = 0;
    
    if(n%2 == 0){
        for(i = 0; i <= n/2 - 1; i++){
            if(i == n/2 - 1){
                minus += v[i];
            }else{
                minus += 2 * v[i];
            }
        }
        for(i = n/2; i < n; i++){
            if(i == n/2){
                plus += v[i];
            }else{
                plus += 2 * v[i];
            }
        }
        ans = plus - minus;
    }else{
        for(i = 0; i <= n/2 - 1; i++){
            minus += 2 * v[i];
        }
        for(i = n/2; i < n; i++){
            if(i == n/2 || i == n/2 + 1){
                plus += v[i];
            }else{
                plus += 2 * v[i];
            }
        }
        sum1 = plus - minus;
        
        plus = 0;
        minus = 0;
        for(i = 0; i <= n/2; i++){
            if(i == n/2 - 1 || i == n/2){
                minus += v[i];
            }else{
                minus += 2 * v[i];
            }
        }
        for(i = n/2 + 1; i < n; i++){
            plus += 2 * v[i];
        }
        sum2 = plus - minus;
        
        if(sum1 > sum2){
            ans = sum1;
        }else{
            ans = sum2;
        }
    }
    
    cout << ans << endl;
}
