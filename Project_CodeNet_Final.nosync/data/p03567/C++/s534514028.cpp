#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int r=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
