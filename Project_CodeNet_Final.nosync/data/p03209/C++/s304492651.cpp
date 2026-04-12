#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

long long int search(long long int n, long long int x){
    if(n == 0 && x == 1){
        return 1;
    }else if(x == 1){
        return 0;
    }else if(x <= pow(2, n+1) - 2){
        return search(n-1, x-1);
    }else if(x == pow(2, n+1) - 1){
        return pow(2, n);
    }else if(x <= pow(2, n+2)-4){
        return pow(2, n) + search(n-1, x-pow(2, n+1)+1);
    }else{
        return pow(2, n+1) - 1;
    }
}

int main(){
    long long int n, x;
    cin >> n >> x;
    cout << search(n, x) << endl;
}