#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    bool pot=false;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            pot=true;
        }
    }
    if(pot==true){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
