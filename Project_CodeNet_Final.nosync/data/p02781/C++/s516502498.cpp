//
// Created by Bhagirathi Nayak on 16/07/20.
//

//#include </usr/local/include/bits/stdc++.h>
//#include <bits/stdc++.h>


using namespace std;

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <math.h>
#include <set>
#include <stack>
#include <bitset>
#include <map>
#include <queue>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <string>

string num;
int k,l;
int dp[1000000][4][2];

int count(int idx,int cnt_k,int already_smaller){

    //cout<<idx<<" "<<cnt_k<<" "<<already_smaller<<"\n";

    if(cnt_k>k)
        return 0;

    if(idx==l)
        return cnt_k==k;

    if(dp[idx][cnt_k][already_smaller]!=-1)
        return dp[idx][cnt_k][already_smaller];

    int curr_digit = num[idx]-'0';

    int lim = already_smaller == 1 ? 9 : curr_digit;

    int sum = 0;
    for (int digit = 0; digit <= lim; ++digit) {
        sum += count(idx+1,
                digit!=0 ? cnt_k+1:cnt_k,
                digit<curr_digit || already_smaller);
    }

    dp[idx][cnt_k][already_smaller] = sum;
    return sum;
}

int main(){
    cin>>num;
    cin>>k;

    l=num.length();

    for (int i = 0 ; i < 1000000 ; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int m = 0; m < 2; ++m) {
                dp[i][j][m] = -1;
            }
        }
    }

    cout<<count(0,0,0)<<endl;
    //cout<<count(0,0,1)<<endl;

    return 0;
}

