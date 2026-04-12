#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;

    int max_H = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++){
        int H;
        cin >> H;

        if (H >= max_H){
            cnt++;
            max_H = H;
        }
    }

    cout << cnt << endl;
}