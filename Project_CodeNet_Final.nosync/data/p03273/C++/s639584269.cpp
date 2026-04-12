//  main.cpp
//  CppTest

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
////////////////////////////////





////////////////////////////////
int main(int argc, const char * argv[]) {
    // input from txt （提出時にこの箇所は削除すること）
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    /////////////////////
    // Write code below /
    /////////////////////
    
    int H,W;
    cin>>H>>W;
    vector<vector<char>>masume(H,vector<char>(W));
    for(int i=0;i<H;i++){
        string A;
        cin>>A;
        for(int j=0;j<W;j++){
            masume.at(i).at(j)=A.at(j);
        }
    }
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(masume.at(i).at(j)=='#'){
                break;
            }
            else if(i==H-1){
                for(int k=0;k<H;k++){
                    masume.at(k).at(j)=' ';
                }
            }
        }
    }
    for(int i=0;i<H;i++){
        bool finish=false;
        for(int j=0;j<W;j++){
            if(masume.at(i).at(j)=='#'){
                break;
            }
            else if(j==W-1){
                finish=true;
            }
        }
        if(finish){
            continue;
        }
        for(int j=0;j<W;j++){
            if(masume.at(i).at(j)!=' '){
                cout<<masume.at(i).at(j);
            }
            if(j==W-1){
                cout<<endl;
            }
        }
    }
    
    return 0;
}
