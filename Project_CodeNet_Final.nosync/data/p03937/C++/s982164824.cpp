#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
    int h, w;
    cin>>h>>w;
    vector<vector<char>> hoge(h, vector<char>(w));
    int step = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
        cin>>hoge.at(i).at(j);
        if(hoge.at(i).at(j)=='#') step++; 
        }
    }
    
    if(step==h+w-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}
