#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;


int main(){
    int N;
    cin >> N;
    ll x[202000];
    ll y[202000];
    for(int i = 0; i < N; i++){
        cin >> x[i];
        y[i] = x[i];
    }

    sort(y, y+N);

    ll m1 = y[N/2-1];
    ll m2 = y[N/2];
    for(int i = 0; i < N; i++){
        if(x[i] > m1){
            cout << m1 << endl;
        }
        else if(x[i] <= m1){
            cout << m2 << endl;
        }
    }

    return 0;

}
