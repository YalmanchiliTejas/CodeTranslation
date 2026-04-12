#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    string s;
    cin>>s;
    bool A=false,B=false;
    for(int i=0;i<3;i++){
        if(s[i]=='A') A=true;
        if(s[i]=='B') B=true;
        if(A&&B) break;
    }
    
    if(A&&B) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}

