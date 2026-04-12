#include<iostream>
#include<cmath>
using namespace std;
int main(){
    char a,yy[5]={'a','e','i','o','u'};
    cin>>a;
    for(int i=0;i<5;i++){
        if(a==yy[i]){
            cout<<"vowel";
            return 0;
        }
    } 
    cout<<"consonant";
    return 0;
}