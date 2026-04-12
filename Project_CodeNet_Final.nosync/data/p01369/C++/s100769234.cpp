#include <algorithm>
#include <iostream>
#include <string>
#include <array>

using namespace std;
const int MAX=32;

array<int, MAX> StrToRL(string s){
    array<int,MAX> num={};
    char l[15]={'q','w','e','r','t','a','s','d','f','g',
                    'z','x','c','v','b'};
    //char r[11]={'y','u','i','o','p','h','j','k','l','n','m'};
    for(int i=0;i<s.size();i++){
        bool lflag=true;
        for(int j=0;j<15;j++){
            if(s[i]==l[j]){
                lflag=false;
                num[i]=1;
            }
            if(lflag){num[i]=-1;}
        }
    }

    return num;
}

int GetChange(array<int, MAX> n){
    int cnt=0;
    for(int i=0;i<MAX-1;i++){
        if(n[i]*n[i+1]==-1){cnt++;}
    }
    return cnt;
}

int main(){
    string s;
    while (cin >> s && !(s=="#")){
        cout<<GetChange(StrToRL(s))<<endl;
    }
    return 0;
}