#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <limits.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    const long long int mod = 1000000007;
    int n;
    cin >> n;

    std::vector<long long int> v;
    std::vector<long long int> vv(n);
    for(int i=0; i<n; i++){
        long long int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    vv[n-1] = 0;
    //cout << vv[n-1] << endl;
    for(int i=n-2; i>=0; i--){
        vv[i] = (vv[i+1]%mod + v[i+1]);
        //cout << vv[i] << endl;
    }
    long long int sum = 0;
    for(int i=0; i<n-1; i++){
        sum += (v[i] * vv[i]%mod);
        //cout << v[i] << ":" << vv[i] << endl;
    }

    cout << sum%mod << endl;
    

    return 0;
}