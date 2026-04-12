#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

void printV(vector<ll> A){
    cout << "[vector]" << endl;
    for(int i=0; i<A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    // input
    int x;
    cin >> x;

    if(x == 3 || x == 5 || x == 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}