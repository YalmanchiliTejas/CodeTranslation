#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <limits>
#include <ios>
#include <iomanip>
using namespace std;

#define rep(i,N) for(int i=0; i<N; i++)
#define revrep(i,N) for(int i=N-1; i>=0; i--)

typedef long long ll;
typedef unsigned int uint;

int main(void)
{
    int N;
    cin >> N;

    vector<int> H(N);

    int ret = 0;
    rep(i,N){
        cin >> H.at(i);

        bool isView = true;
        for(int j = 0; j < i; j++) {
            if (H.at(j) > H.at(i)) {
                isView = false;
                break;
            }
        }
        if (isView) ret ++ ;
    }

    cout << ret << endl;

    return 0;
}
