//
//  main.cpp
//  CoderTest
//
//  Created by yuya on 2019/05/20.
//  Copyright © 2019 yuya. All rights reserved.
//

#include<bits/stdc++.h>
#define ll long long
using namespace std;




int main(){
    
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H);
    vector<int> rowchk(H), columnchk(W); // 黒があるなら1
    
    for(int i=0;i<H;i++){
        a[i].assign(W, 0);
        for(int j=0;j<W;j++){
            cin >> a[i][j];
            if(a[i][j]=='#') {
                rowchk[i]=1;
                columnchk[j]=1;
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(rowchk[i]==1 && columnchk[j]==1) {
                cout << a[i][j];
            }
        }
        if(rowchk[i]==1) cout << endl;
    }
    return 0;
}
