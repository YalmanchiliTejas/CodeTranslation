#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
int rec1(string s){
    vector<int>a;
    vector<bool>b;
    REP(i,s.size()){
        if(i%2==0)a.push_back(s[i]-'0');
        else b.push_back(s[i]=='*'?true:false);
    }
    REP(i,b.size()){
        if(b[i]){
            a[i+1]=a[i]*a[i+1];
            a[i]=0;
        }
    }
    int sum=0;
    REP(i,a.size()){
        sum+=a[i];
    }
    return sum;
}
int rec2(string s){
    int res=s[0]-'0';
    for(int i=2;i<s.size();i+=2){
        if(s[i-1]=='*'){
            res*=(s[i]-'0');
        }else{
            res+=(s[i]-'0');
        }
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    int bob;
    cin>>bob;
    int a=rec1(s);
    int b=rec2(s);
    if(a==bob){
        if(b==bob){
            cout<<"U"<<endl;
        }else{
            cout<<"M"<<endl;
        }
    }else{
        if(b==bob){
            cout<<"L"<<endl;
        }else{
            cout<<"I"<<endl;
        }
    }
}