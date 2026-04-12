#include <bits/stdc++.h>
    using namespace std;
    int main(){
        int N, M;
        cin >> N >> M;

        if(N==M){
            cout << "Yes" << endl;
        }
        else if(M<N){
            cout << "No" << endl;
        }
    }