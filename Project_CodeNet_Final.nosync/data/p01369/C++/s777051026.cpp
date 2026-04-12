#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true){
        string str;
        int before, now;
        string right="yuiophjklnm";
        int cnt=0;
        cin >> str;
        if(str=="#") break;
        if(right.find(str[0])!=string::npos) before = 1;
        else before = 0;
        for(int i=1;i<str.size();++i){
            if(right.find(str[i])!=string::npos) now = 1;
            else now = 0;
            if(before!=now) ++cnt;
            before = now;
        }
        cout << cnt << endl;
    }
}