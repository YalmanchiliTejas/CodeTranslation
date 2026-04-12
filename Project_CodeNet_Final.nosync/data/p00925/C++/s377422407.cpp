#include <bits/stdc++.h>
using namespace std;
#define reep(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) reep((i),0,(n))
int foo2(string s){
    int ret=0;
    stringstream ss;
    ss<<s;
    ss>>ret;
    char t;
    int tt;
    // cout<<s<<endl;
    while(ss>>t){
        ss>>tt;
        if(t=='+'){
            ret+=tt;
        }
        else{
            ret*=tt;
        }
    }
    return ret;
}
int foo1(string s){
    rep(i,s.size()){
        if(s[i]=='*'){
            int l=i-1;
            int r=i+1;
            while(isdigit(s[l])) l--;
            while(isdigit(s[r])) r++;
            l++;
            r--;
            stringstream ss;
            ss<<atoi(s.substr(l,i-l).c_str())*atoi(s.substr(i+1,r-i).c_str());
            string t;
            ss>>t;
            return foo1(s.substr(0,l)+t+s.substr(r+1));
        }
    }
    return foo2(s);
}
int main(){
    string s;
    int a;
    cin>>s>>a;
    // cout<<foo1(s)<<endl;
    // cout<<foo2(s)<<endl;
    bool f1=(a==foo1(s));
    bool f2=(a==foo2(s));
    if(f1&&f2) cout<<"U"<<endl;
    else if(f1) cout<<"M"<<endl;
    else if(f2) cout<<"L"<<endl;
    else  cout<<"I"<<endl;
}