//
// Created by yuu on 2019-04-23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;


int main(void){
    int N;
    string S;
    int K;

    cin>>N;
    cin>>S;
    cin>>K;

    for (int i = 0; i < N; ++i) {
        if(S[K-1] == S[i]){
            continue;
        }
        S[i] = '*';
    }


    cout<<S<<endl;

    return 0;
}