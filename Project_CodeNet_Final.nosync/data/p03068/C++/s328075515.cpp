#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main(void){
    int n,k;string s;cin>>n>>s>>k;
    char x=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]!=x)cout<<"*";
        else cout<<x;
    }
    cout<<endl;
    
    return 0;
}
