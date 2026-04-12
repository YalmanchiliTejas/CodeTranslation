//  main.cpp
//  CppTest

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

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

    char c;
    cin>>c;
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        cout<<"vowel"<<endl;
    }
    else{
        cout<<"consonant"<<endl;
    }
    
    
    return 0;
}
