#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int X[N];
    int Y[N];
    for(int i= 0;i<N;i++){
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(X,X+N);
    int ans1 = X[N/2 -1];
    int ans2 = X[N/2];
    for(int i = 0;i<N;i++){
        if(Y[i] <= ans1) cout << ans2 << endl;
        else cout << ans1 << endl;
    }
    return 0;
}
