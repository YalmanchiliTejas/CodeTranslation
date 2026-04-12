#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define IFOR(i,a) for(int i=(a);;i++)
#define REP(i,n)  FOR(i,0,n)
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INPUT \
FILE *fp; \
fp=fopen("input.text","r");



int main() {
    int N,cnt=0,high=0;
    cin >> N;
    int takasa[N];
    
    FOR(i, 0, N) cin >> takasa[i];
    FOR(i, 0, N){
        if (takasa[i]>=high) {
            high=takasa[i];
            cnt+=1;
            
        }
        
    }

    
    cout << cnt << endl;
    return 0;
}

