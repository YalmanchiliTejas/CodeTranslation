#include <bits/stdc++.h>
using namespace std;

#define ll  long long


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<3;i++){
        if(s[i]-'A'==0){
            ++a;
        }else if(s[i]-'B'==0){
            ++b;
        }
    }

    if(a==0||b==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
        
    return 0;
}