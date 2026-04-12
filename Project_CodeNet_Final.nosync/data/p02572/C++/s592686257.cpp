#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

#define X 1000000007


int main(){
    int n;
    cin>>n;
    vector<int> b(n);
    int a;
    ll tmp = 0;
    ll sum = 0;
    for(int i = 0;i<n;i++){
        cin>>a;
        tmp = (a + tmp) % X;
        b[i] = tmp;
    }
    
    sum = ll(b[0]*ll(X +b[n-1]-b[0]))%X;
    for(int i = 1; i < n - 1;i++){
        sum = ll(sum + ll(ll(X + b[i]-b[i-1]) % X * ll(X+b[n - 1] - b[i])% X)) % X;
    }
    cout<<sum<<endl;
    return 0;
}  
