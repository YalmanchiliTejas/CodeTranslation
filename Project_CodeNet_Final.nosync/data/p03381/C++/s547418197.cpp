#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
int N, X[200010];
int T[200010];
/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>N;
    REP(i,0,N){
        cin>>X[i];
        T[i] = X[i];
    }

    sort(X, X+N);
    int midInd = N/2;

    REP(i,0,N){
        if(T[i] < X[midInd]){
            cout<<X[min(N-1, midInd)]<<endl;
        }else{
            cout<<X[max(0, midInd-1)]<<endl;
        }
    }

    return 0;
}
