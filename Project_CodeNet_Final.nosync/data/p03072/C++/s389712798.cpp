#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; ++i) cin >> H[i];
    int  sum = 1;
    
    for(int i = 1; i < N; ++i){
        bool flag = true;
        for(int j = 0; j < i; ++j){
            if(H[j] > H[i]) flag = false;
        }
        if(flag) sum += 1;
    }
    cout  << sum << endl;
}