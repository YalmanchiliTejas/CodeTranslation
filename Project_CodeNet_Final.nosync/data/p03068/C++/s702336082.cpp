#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    string s;
    cin >>n >>s >>k;
    char c=s[k-1];
    for(auto&& w:s){
        if(w!=c)w='*';
    }
    cout<<s<<endl;
}