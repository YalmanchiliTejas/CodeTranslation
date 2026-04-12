#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <utility>
using namespace std;

long l[51];
long p[51];

long f(long n, long x){
    if(n == 0){
        if(x == 0) return 0;
        else return 1;
    }
    if(x == 0) return 0;
    else if(x <= l[n-1]+1) return f(n-1, x-1);
    else if(x == (l[n]-1)/2 + 1) return p[n-1] + 1;
    else if(x >= (l[n]-1)/2 + 1) return p[n-1] + 1 + f(n-1, x - 2 - l[n-1]);
    else return p[n];
}

int main(){
    long n, x;
    cin >> n >> x;
    
    l[0] = 1;
    p[0] = 1;
    for(int i=1;i<=n;i++){
        l[i] = l[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    cout << f(n, x) << endl;
    return 0;
}
