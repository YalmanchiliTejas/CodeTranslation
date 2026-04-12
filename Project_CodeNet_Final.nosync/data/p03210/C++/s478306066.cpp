#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <math.h>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int X;
    cin >> X;

    if(X == 3 || X == 5 || X == 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
