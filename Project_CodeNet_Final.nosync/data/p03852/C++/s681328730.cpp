#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
char a;
cin>>a;
string s="aiueo",ans="consonant";
for(int i=0;i<5;i++){
    if(s[i]==a){
        ans="vowel";
    }
}

cout<<ans<<endl;
    return 0;
}
