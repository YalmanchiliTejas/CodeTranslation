#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int N,H[100];
    cin >> N;

    rep(i,N){
        cin >> H[i];
    }

    int count=0;
    for(int i=0;i<N;i++){
        bool dekai=true;
        for(int j=0;j<i;j++){
            if(H[j] > H[i]){
                dekai=false;
                break;
            }
        }
        if(dekai){
            count++;
        }
    }

    cout << count <<endl;
}