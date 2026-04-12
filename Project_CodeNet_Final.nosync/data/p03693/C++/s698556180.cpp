#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, g, b;
    cin >> r >> g >> b;
    if((r * 100 + g * 10 + b) % 4 == 0){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }


    return 0;
}
