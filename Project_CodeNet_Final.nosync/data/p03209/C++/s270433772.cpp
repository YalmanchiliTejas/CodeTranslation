#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <cstdio>
#include <math.h>
using namespace std;
int n;
long long x;
long long p[60];
long long num[60];

long long cal(long long k,long long j){
    if(k==0){
        if(j<=0){
            return 0;
        }else{
            return 1;
        }
    }else if(j==1){
        return 0;
    }else if(j>1&&j<=num[k-1]+1){
        return cal(k-1,j-1);
    }else if(j==num[k-1]+2){
        return p[k-1]+1;
    }else{
        return p[k-1]+1+cal(k-1,j-2-num[k-1]);
    }
}

int main(){
    cin >> n >> x;
    p[0] = 1;
    num[0] = 1; 
    for(int i=1;i<50;i++){
        p[i] = p[i-1]*2+1;
        num[i] = num[i-1]*2+3;
    }
    cout << cal(n,x) << endl;
}