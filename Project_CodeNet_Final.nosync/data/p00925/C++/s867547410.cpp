#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cin>>s;
    int num;
    cin>>num;
    int l2r=s[0]-'0';
    for(int i=1;i<s.size();i+=2){
        if(s[i]=='*'){
            l2r*=s[i+1]-'0';
        }else{
            l2r+=s[i+1]-'0';
        }
    }
    stack<int> S;
    S.push(s[0]-'0');
    for(int i=1;i<s.size();i+=2){
        if(s[i]=='*'){
            S.top()*=s[i+1]-'0';
        }else{
            S.push(s[i+1]-'0');
        }
    }
    int mf = 0;
    while(!S.empty()){
        mf+=S.top();
        S.pop();
    }
    bool L = num==l2r;
    bool M = num==mf;
    char ans;
    if(L&&M){
        ans = 'U';
    }else if(L){
        ans = 'L';
    }else if(M){
        ans = 'M';
    }else{
        ans = 'I';
    }
    cout<<ans<<endl;
    return 0;
}