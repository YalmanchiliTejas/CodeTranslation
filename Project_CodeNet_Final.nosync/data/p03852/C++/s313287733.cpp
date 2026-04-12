#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    
    char c;
    cin>>c;
    string ans="consonant";
    char set[]={'a','i','u','e','o'};
    for(int i=0;i<sizeof(set)/sizeof(set[0]);i++){if(c==set[i])ans="vowel";}
    cout<<ans<<endl;
    
    return 0;
}