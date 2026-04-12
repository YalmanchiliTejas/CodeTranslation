#include<bits/stdc++.h>

using namespace std;
//证明是我SadLava写的
char a[5]={'a','e','i','o','u'};//伟大的表

int main(){
    char c;
    c=getchar();
    for(int i=0;i<5;i++){
        if(c==a[i]){
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
    return 0;
}