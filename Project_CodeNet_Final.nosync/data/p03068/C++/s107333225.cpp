#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define SORTD(a) sort(a.rbegin(), a.rend());
#define ll long long
#define INF 1000000000000000000
#define INT_MAX 2147483647

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(){
    int N,K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    char c = S[K-1];
    REP(i, S.length()){
        if(S[i]!=c){
            S[i] = '*';
        }
    }
    cout << S << endl;
    return 0;
}
