#include <iostream>
using namespace std;

long long sum[51] = {1};

long long burger(long long level, long long *remain){
    if(*remain <= 0){
        return 0;
    }
    
    if(level == 0){
        if(*remain > 0){
            (*remain)--;
            return 1;
        }else{
            return 0;
        }
    }
    
    long long ans = 0;
    if(*remain >= sum[level]){
        ans = sum[level] / 2 + 1;
        *remain -= sum[level];
        return ans;
    }else{
        (*remain)--;
        ans += burger(level - 1, remain);
    }
    
    if(*remain <= 0){
        return ans;
    }
    
    ans++;
    (*remain)--;
    
    if(*remain <= 0){
        return ans;
    }
    
    ans += burger(level - 1, remain);
    
    return ans;
}

int main(void){
    long long n, x;
    cin >> n >> x;
    
    for(long long i = 1; i <= 50; i++){
        sum[i] = sum[i - 1] * 2 + 3;
    }
    
    cout << burger(n, &x) << endl;
}
