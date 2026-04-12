#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;
using ll = long long int;

int main()
{
    int N,M;
    cin >> N >> M;
    int A[N][N] = {};
    for (int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        A[a-1][b-1] = 1;
        A[b-1][a-1] = 1;
    }

    int B[N-1];
    for (int i=2; i <= N; i++){
        B[i-2] = i;
    }
    int ans = 0;
    do {
        int c = 1;
        if (A[0][B[0]-1] == 0) {
            c = 0;
        }
        for (int i = 0; i < N-2; i++) {
            if (A[B[i]-1][B[i+1]-1] == 0 || c == 0){
                c = 0;
                break;
            }
        }
        if (c == 1) {
            ans++;
        }
    } while(next_permutation(B,B+N-1));
    cout << ans << endl;

}
