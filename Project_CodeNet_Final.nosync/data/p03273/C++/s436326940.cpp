#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>
#include<algorithm>
#include<complex>
#include<queue>
#include<stdlib.h>
#include<map>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>

#define ll long long

using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    vector<int> H_m;
    vector<int> W_m;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j]=='#'){
                H_m.push_back(i);
                W_m.push_back(j);
            }
        }
    }
    sort(H_m.begin(),H_m.end());
    sort(W_m.begin(),W_m.end());
    for(int i=0;i<H_m.size();i++){
        for(int j=0;j<W_m.size();j++){
            while(i!=H_m.size()-1&&H_m[i]==H_m[i+1]){
                i++;
            }
            while(j!=W_m.size()&&W_m[j]==W_m[j+1]){
                j++;
            }
            cout << a[H_m[i]][W_m[j]];
        }
        cout << endl;
    }
    return 0;
}

