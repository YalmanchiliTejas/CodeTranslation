#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

char f(char a, char b){
    if(a=='T' && b=='F') return 'F';
    return 'T';
}

int main(){
    int N; cin >> N;
    char cur; cin >> cur;
    for(int i=0; i<N-1; i++){
        char p; cin >> p;
        cur = f(cur, p);
    }
    
    cout << cur << endl;
    return 0;
}

