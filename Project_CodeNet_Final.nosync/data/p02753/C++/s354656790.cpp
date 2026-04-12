//##MohK
//08/03/2020.... 6,35.
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll counter=0,counterr=0;
    string s;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='A')counter++;
        else counterr++;
    }
    if(counter==3||counterr==3)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}
