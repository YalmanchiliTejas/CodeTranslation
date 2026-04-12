//
//  main.cpp
//  Shik_And_Stone
//
//  Created by Uttam Datta on 31/05/19.
//  Copyright © 2019 Uttam Datta. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int rows,columns;

bool ans(string A[]){
    pair <int,int> d;
    for(int i = 0; i < rows-1; i++){
        for(int j = 0; j < columns-1; j++){
            if(A[i][j] = '#'){
                d = make_pair(i, j);
            if((A[i][j] == '#' && A[i+1][j] == '#' && A[i][j+1] == '#') || (d.second>j)){
                return false;
            }
                
            }
        }
    }
    return true;
}


int main(){
    cin >> rows >> columns;
    string A[rows];
    for(int i = 0; i < rows; i++){
        cin >> A[i];
    }
    bool res = ans(A);
    if(res){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
    return 0;
}
