#include <iostream>
using namespace std;

int main(){
        string str;
        cin>>str;
        bool ans=false;
        for(int i=0; i<str.size()-1; i++){
                if(str[i]=='A' && str[i+1]=='C'){
                        ans=true;
                        break;
                }
        }
        if(ans) cout<<"Yes";
        else cout<<"No";
        return 0;
}
