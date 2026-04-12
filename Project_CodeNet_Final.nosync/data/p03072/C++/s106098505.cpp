#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, i, j, count;

    cin >> N;
    count = N;

    vector<int> H(N);

    for(i=0;i<N;++i){

        cin >> H[i];
    }

    for(i=1;i<N;++i){

        for(j=0;j<i;++j){

            if(H[i] < H[j]){
                count--;
                break;
            }
        }

    }

    cout << count << endl;

}