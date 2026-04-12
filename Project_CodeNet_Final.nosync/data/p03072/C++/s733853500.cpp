#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);

    int max=0;
    int count=0;
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    for(int i=0;i<n;i++){
        if(max <= h[i]){
            count++;
            max = h[i];
        }
    }

    cout << count << endl;

    
    
}