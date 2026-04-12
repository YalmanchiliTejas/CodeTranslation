#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<array>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> h(n);

    for(int i = 0;i < n; ++i){
        cin >> h[i];
    }

    int count = 1;

    for(int i = 1;i < n; ++i){

        bool f = true;

        for(int j = 0; j < i; ++j){
            if(h[j] > h[i])f = false;
        }

        if(f)++count;

    }

    cout << count << endl;

    return 0;
}