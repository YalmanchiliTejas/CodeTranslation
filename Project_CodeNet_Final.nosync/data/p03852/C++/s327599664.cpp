#include <iostream>
using namespace std;
int main(){
    string v="aeiou";
    char c;
    cin>>c;
    for(int i=0;i<5;i++){
        if(c==v[i]){
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
}