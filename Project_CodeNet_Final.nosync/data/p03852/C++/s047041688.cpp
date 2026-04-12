#include<bits/stdc++.h>
using namespace std;


bool isvowel(char c){
    string vowels = "aeiou";
    for(int i=0; i<5; i++)if(vowels[i]==c)return true;
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    cin>>c;
    if(isvowel(c))cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;

return 0;
}
