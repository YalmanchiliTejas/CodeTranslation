#include <iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    string ss;
    cin>>ss;
    if(ss=="a" || ss=="e" || ss=="i" || ss=="o" || ss=="u"){
        cout<<"vowel"<<endl;
    }
    else cout<<"consonant"<<endl;
    return 0;
    // Your code here!
    
}
