#include <iostream>
#include <string>

namespace Mylib{
    using namespace std;
    
    void Instring(string& x){
        cin >> x;
    }
    
    void showString(string& x){
        cout << x << endl;
    }
    
    bool checkAtoB(string& x){
        for(int i=1;i<x.length();i++){
            if(x[i-1]!=x[i])return true;
        }
        return false;
    }
    void showflag(bool flg){
        if(flg==true){
            cout << "Yes" << endl;
            
        }else{
            cout << "No" << endl;
        }
    }
    
}
int main(void){
    std::string inStr;
    Mylib::Instring(inStr);
    bool flag;
    flag=Mylib::checkAtoB(inStr);
    Mylib::showflag(flag);
    
    
    
    
    return 0;
}