#include <iostream>
#include<string>
using namespace std;

int main() {
string c="aeiou";
string s;
cin>>s;
int count=0;
for(int i =0;i<5;i++){
    if(c[i]==s[0]){
        count++;
        break;
    }
}
if(count==1){
    cout<<"vowel";
}
else{cout<<"consonant";}
    return 0;
}