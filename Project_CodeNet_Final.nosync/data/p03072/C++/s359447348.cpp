#include "bits/stdc++.h"
#define REP(N) for(int i=0; i<N; i++)
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int* H = (int*)malloc(sizeof(int)*N);
    REP(N){cin >> H[i];}

    int minMtHeightNearestSea = 0;
    int ans = 0;
    REP(N)
    {
        if(H[i] >= minMtHeightNearestSea)
        {
            minMtHeightNearestSea = H[i];
            ans++;
        }
    }

    cout << ans << endl;

    free(H);
    return 0;
}
