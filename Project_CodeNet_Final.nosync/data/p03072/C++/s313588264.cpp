//
// Created by yuu on 2019-04-16.
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
    int A;
    cin>>A;
    vector<int> H;
    for (int i = 0; i < A; ++i) {
        int temp;
        cin>>temp;
        H.push_back(temp);
    }
    int ans = 0;
    int max=-1;
    for (int j = 0; j < H.size(); ++j) {
        if(max<=H[j]){
            ans++;
            max = H[j];
        }
    }

    cout<<ans<<endl;


    return 0;
}