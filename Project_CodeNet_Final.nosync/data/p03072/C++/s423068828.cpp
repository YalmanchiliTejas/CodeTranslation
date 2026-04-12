//
// Created by yuu on 2019-04-13.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;


int main(void){
    int N;
    cin>>N;
    int H[1000];
    for (int i = 0; i < N; ++i) {
        cin>>H[i];
    }
    int ans = 0;

    for (int j = 0; j <N; ++j) {
        bool flag = true;
        int A = H[j];
        for (int i=j-1; i>=0; i--){
            if(H[i]>A){
                flag = false;
            }
        }
        if(flag){
            ans++;
        }
    }
    
    cout<<ans<<endl;


    return 0;
}