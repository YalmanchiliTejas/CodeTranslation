#include <iostream>
#include<string>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main(){
    char c;
    cin>>c;

    char v[]="aoeiu";
    for(int i=0; i<5; i++){
        if(v[i]==c){
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
    return 0;
}