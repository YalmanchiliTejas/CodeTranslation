#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, wcnt[55][50];
    for(int i=0;i<55;++i) for(int j=0;j<50;++j) wcnt[i][j] = 0;
    cin >> n;
    string s[55];
    for(int i=0;i<n;++i) cin >> s[i];
    for(int i=0;i<n;++i){
        int len = s[i].size();
        for(int j=0;j<len;++j){
            int tar = s[i][j];
            ++wcnt[i][tar-97];
        }
    }
    for(int j=0;j<27;++j){
        int min = 10000;
        for(int i=0;i<n;++i){
            if(min > wcnt[i][j]) min = wcnt[i][j];
        }
        for(int i=0;i<min;++i){
            cout << (char)(j+97);
        }
    }
    cout << endl;
}