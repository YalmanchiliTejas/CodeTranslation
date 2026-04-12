#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;


int main(){
    string s;
    cin>>s;
    int cnt=0;
    
    if(s[0]==s[1] && s[1]==s[2])
        cnt++;
    
    cout<<(cnt ? "No":"Yes")<<endl;
}