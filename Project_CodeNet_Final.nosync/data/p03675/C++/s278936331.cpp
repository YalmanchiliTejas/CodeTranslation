#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    REP(i,n){
        cin>>a[i+1];
    }
    vector<int> b;
        for(int i=n;i>0;i-=2){
            b.push_back(a[i]);
        }
        //MX奇数なら２開始
        for(int i=2-(n+1)%2;i<n;i+=2) {
            b.push_back(a[i]);
        }

    REP(i,b.size()){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    return 0;
}