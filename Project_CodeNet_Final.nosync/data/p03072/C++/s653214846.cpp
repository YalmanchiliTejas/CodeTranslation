#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,ans = 1;
    cin >> N;
    vector<int> h(N);

    for(int i = 0; i < N; i++){
        cin >> h.at(i);
    }

    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < i; j++){

            if(h.at(i) >= h.at(j)){
                count++;
            }else{
                break;
            }
            if(count == i){
                ans++;
                break;
            }            
            
        }
    }

    cout << ans << endl;
}