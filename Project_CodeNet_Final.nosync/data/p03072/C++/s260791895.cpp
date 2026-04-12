#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int>H(N);
    int count=1, tmp=0;
    for(int i=0; i<N; i++){
        cin >> H.at(i);
    }

    int j;
    for(int i=N-1; i>0; i--){
        tmp=0;
        for(j=i-1; j>-1; j--){
            if(H.at(i)<H.at(j)){
                break;
            }
        }
        if(j<0){
            count++;
        }
    }

    cout << count << endl;

  return 0;
}
