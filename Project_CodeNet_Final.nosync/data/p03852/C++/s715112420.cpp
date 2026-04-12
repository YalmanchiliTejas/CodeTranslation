// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[5]={'a','e','i','o','u'},k;
    k=getchar();
    for(int i=0;i<5;i++){
        if(k==a[i]){
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
    return 0;
}