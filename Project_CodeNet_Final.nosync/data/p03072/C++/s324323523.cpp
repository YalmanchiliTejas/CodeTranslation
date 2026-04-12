#include <bits/stdc++.h>
using namespace std;
    
int main() {
    long N,H[20];
    long result;
    int i,max;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> H[i];
    }
    max = H[0];
    result = 1;
    for(i=1;i<N;i++){
        if(H[i]>=max){
            result++;
            max = H[i];
        }
    }

    cout << result << endl;
}



