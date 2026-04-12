#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define pb push_back
#define mp make_pair
#define M 10e9+7
int main(){
    ll t=1;
    while(t--){
    string s;
    cin>>s;
    set<char>st;
    for(ll i=0;i<s.size();i++){
        st.insert(s[i]);
    }
    if(st.size()==2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}}