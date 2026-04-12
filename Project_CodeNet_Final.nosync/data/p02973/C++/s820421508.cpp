#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    const int MAX_N = 1e5 + 10;
    int N;
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; ++i){
        A.push_back(-1);
    }

    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        int b = lower_bound(A.begin(), A.end(), a) - A.begin() - 1;
        A[b] = a;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i){
        if(A[i] >= 0) ans++;
    }
    cout << ans << endl;
}