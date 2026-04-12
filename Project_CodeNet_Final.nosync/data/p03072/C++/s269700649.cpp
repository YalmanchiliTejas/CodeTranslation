#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    vector<int> h(N);
    int i = 0;
    int max = 0;
    int ans = 0;
    while (i < N) {
        cin >> h[i];
        if (h[i] >= max) ans++;
        if (max < h[i]) max = h[i];
        i++;
    }
    cout << ans << endl;
}