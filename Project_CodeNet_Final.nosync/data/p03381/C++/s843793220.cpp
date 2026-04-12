//
//  main.cpp
//  GCJ
//
//  Created by shitian.ni on 2018/06/19.
//  Copyright © 2018 shitian.ni. All rights reserved.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin>>N;
    vector<int>vec(N);
    vector<int>sorted(N);
    for(int i=0;i<N;i++){
        cin>>vec[i];
        sorted[i] = vec[i];
    }
    sort(sorted.begin(),sorted.end());
    int left = sorted[N/2 - 1], right = sorted[N/2];
    for(int i=0;i<N;i++){
        if(vec[i]>=right){
            cout<<left<<endl;
        } else {
            cout<<right<<endl;
        }
    }
    
    return 0;
}
