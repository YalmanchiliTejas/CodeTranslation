#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
    char c;
    cin>>c;
    string str="aiueo";
    int b=0;
    for(int i=0;i<str.size();i++){
        if(c==str.at(i)){
            cout<<"vowel";
            b=1;
            break;
        }
    }
    if(!b){
        cout<<"consonant";
    }
}