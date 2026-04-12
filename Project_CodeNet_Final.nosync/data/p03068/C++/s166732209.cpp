#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    string s;
    cin>>a>>s>>b;
    
    c = s.size();
    
    char d = s[b-1];
    for(int i = 0;i<c;i++){
        if(s[i]!=d)
        cout<<'*';
        else
        cout<<s[i];
    }
    cout<<endl;
}
