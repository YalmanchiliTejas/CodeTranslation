#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll calcm(string s){
    ll ret=0;
    ll tmp=0;
    int ind=0;
    char op='+';
    while(ind<s.size()){
        ll tn=s[ind]-'0';
        ++ind;
        if(ind>=s.size()||s[ind]=='+'){
            if(op=='*')tmp*=tn;
            else tmp+=tn;
            ret+=tmp;
            tmp=0;
        }
        else{
            if(op=='*')tmp*=tn;
            else tmp+=tn;
        }
        op=s[ind];
        ++ind;
    }
    return ret+tmp;
}

ll calc(string s){
    ll ret=0;
    int ind=0;
    char op='+';
    while(ind<s.size()){
        ll tn=s[ind]-'0';
        ++ind;
        if(op=='+')ret+=tn;
        else ret*=tn;
        op=s[ind];
        ++ind;
    }
    return ret;
}

ll solve(string s,bool mul){
    if(mul)return calcm(s);
    else return calc(s);
}

int main(){
    string s;
    cin>>s;
    ll res;
    cin>>res;
    bool ml=false,l=false;
    ml=(res==solve(s,true));
    l=(res==solve(s,false));

    if(ml&&!l)cout<<"M"<<endl;
    else if(!ml&&l)cout<<"L"<<endl;
    else if(ml&&l)cout<<"U"<<endl;
    else cout<<"I"<<endl;
    return 0;
}
