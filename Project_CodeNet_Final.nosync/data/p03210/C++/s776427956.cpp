#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
#include <climits>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

int n;

int main() {
    cin >> n;
    if(n==3||n==5||n==7){
        put("YES");
        return 0;
    }else{
        put("NO");
        return 0;
    }
    return 0;
}
