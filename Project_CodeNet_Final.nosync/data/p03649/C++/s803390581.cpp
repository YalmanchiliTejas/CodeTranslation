#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
//#include <stack>
#include <climits>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

ll k = 0;
int n;
//vector<ll> a(n);

bool bor(vector<ll> a){
    bool rtn = false;
    REP(i,n){
        if(a[i]>=n){
            rtn = true;
        }
    }
    return rtn;
}

int main(void){
    cin >> n;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }
    while(bor(a)){
        REP(i,n){
            if(a[i]>=n){
                ll num = a[i]/n;
                k += num;
                a[i]=a[i]%n-num;
                REP(j,n){
                    a[j]+=num;
                }
            }
        }
    }
    put(k);
    return 0;
}
