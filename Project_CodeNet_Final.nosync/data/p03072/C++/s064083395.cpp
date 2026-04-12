#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define Rep(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define Repr(i, b, e) for(int (i) = (b) - 1; (i) >= (e); --(i))
#define Print(x) cout << (x) << endl 
#define Min2(a, b) ((a) < (b)) ? (a) : (b)
#define Max2(a, b) ((a) > (b)) ? (a) : (b)

typedef long long ll;

using namespace std;

int N;
int H[20];

bool solve(int i){
    Rep(j, 0, i){
        if(H[j] > H[i]) return false;
    }
    return true;
}

int main(){
    int ans = 0;
    cin >> N;
    Rep(i, 0, N) cin >> H[i];
    Rep(i, 0, N){
        if(solve(i)) ans++;
    }
    Print(ans);
    return 0;
}