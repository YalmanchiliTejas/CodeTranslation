#include <iostream>
#include <string>
using namespace std;
int main(){
    int i,n,k;
    string s;
    char a;
    cin>>n>>s>>k;
    a = s[k-1];
    for(i=0;i<n;i++){
        if(s[i]!=a){
            s[i]='*';
        }
    }
    cout<<s;
}