#include <iostream>
using namespace std;

int N, S;
void solve(){
    while (cin >> N && N > 0){
        int sum = 0;
        int min = 1000000;
        int max = -1;
        for (int i = 0; i < N; i++){
            cin >> S;
            sum += S;
            if (min > S) min = S;
            if (max < S) max = S;
        }
        cout << (sum - max - min)/(N-2) << endl;
    }
}



int main(){
    solve();
}

