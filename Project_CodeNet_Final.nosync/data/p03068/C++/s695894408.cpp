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

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    char c = S[K - 1];
    Rep(i, 0, N){
        if(S[i] != c) S[i] = '*';
    }
    Print(S);
    return 0;
}