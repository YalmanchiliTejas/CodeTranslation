#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,b=0;
    cin >> N;
    vector<int> Height(N);
    for(int i=0; i<N; i++){
        cin >>Height.at(i);
    }
    for(int j = 0; j < N;j++){
        bool is_candidate = true;
        for(int k = 0; k < j; k++){
            if(Height.at(k) >Height.at(j)){
                is_candidate= false;
                break;
            }
        
        }
        if(is_candidate) {
            b++;
        }
    }

    cout << b << endl;
}