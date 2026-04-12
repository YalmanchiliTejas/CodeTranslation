#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void){
    int N, M; cin >> N >> M;
    bool c[8][8] = {0};
    array<int, 8> arr;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        c[--a][--b] = true; c[b][a] = true;
    }
    for(int i = 0; i < N; i++) arr[i] = i;

    int res = 0;
    do{
        // cout << "permutation: ";
        // for_each(arr.begin(), arr.begin()+N, [](auto x){cout << x << ' ';});
        // cout << '\n';

        for(int i = 0; i < N-1; i++){
            // cout << "---" << arr[i] << ' ' << arr[i+1] << '\n';
            if(not c[arr[i]][arr[i+1]]) break;
            if(i == N-2){
                res++;
                // cout << "res is incremented\n";
            }
        }
    }while(next_permutation(arr.begin()+1, arr.begin()+N));

    cout << res << '\n';
    return 0;
}