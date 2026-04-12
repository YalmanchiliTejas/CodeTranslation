#include <bits/stdc++.h>
#define repeat(n) for(int i = 0; i < n; i++)
using namespace std;

int main(){

    int n;
    cin >> n;
    int h[n];
    repeat(n) cin >> h[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        bool isCandidate = true;
        for(int j = 0; j < i; j++){
            if(h[j] > h[i]){
                isCandidate = false;
                break;
            }
        }
        if(isCandidate)
            res++;
    }

    cout << res << endl;
}