#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;
    k--;
    
    for(int i =0;i<n;i++){
        if (s[i]!=s[k]){
            cout<<"*";
        }
        else{
        cout<<s[i];
        }
    }
}
