#include "bits/stdc++.h"
using namespace std;
int main(){
    int N;
    cin >> N;
    int m = 0,n = 0,i = 0,x;
    while(i < N){
        cin >> x;
        if(x >= m){
            m = x;
            n++;
        }
        i++;
    }
    cout << n << endl;
}