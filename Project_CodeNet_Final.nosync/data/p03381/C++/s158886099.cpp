#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <random>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>
#define REP(i,x) for(int i=0; i<(x); i++)
typedef long long ll;

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int x[n];
    int cp[n];
    REP(i, n){
        cin>>x[i];
        cp[i] = x[i];
    }
    sort(cp, cp+n);
    int med_b = cp[n/2];
    int med_s = cp[(n/2)-1];
    REP(i, n){
        if(x[i] >= med_b){
            cout<<med_s<<endl;
        } else {
            cout <<med_b<<endl;
        }
    }
    
    
    return 0;
}
