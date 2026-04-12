//078 B - ISU 2017/11/11
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int x , y , z; cin >> x >> y >> z;
    int min;
    int i;
    for(i=1;;++i){
        if(x-y*i-(z*(i+1))>=0) continue;
        else {--i; break;}
    }
    cout << i << endl;
}