#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
//for (int i = 0; i < N; i++){}
//for (int i = 0; i < N; i++){}

int main() {
    int N;
    cin >> N;

    int H[N];
    for (int i = 0; i < N; i++){
        cin >> H[i];
    }

    int maxs = H[0];

    int res=1;
    for (int i = 1; i < N; i++){
//        cout << H[i] << "-" << maxs << endl;
        if(H[i] >= maxs){
            res++;
        }
        maxs = max(maxs, H[i]);
    }
    cout << res << endl;
}