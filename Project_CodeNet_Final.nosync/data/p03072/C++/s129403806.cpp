#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define REP(i, n) for(int i=1; i<=(int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    int count = 0;
    int max = 0;

    rep(i, N){
        cin >> H[i];
    }

    rep(i, N){
        if (H[i] >= max){
            max = H[i];
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

