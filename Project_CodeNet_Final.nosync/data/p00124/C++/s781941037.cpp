#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
struct data{
    string str;
    int n,p;
    data(string s,int a,int b){
        str=s;n=a;p=b;
    }
    data(){}

    bool operator>(const data &d)const{
        if(p!=d.p)return (p>d.p);
        else return (n<d.n);
    }
};
int main(){
    int n;
    bool flag=false;
    while(cin>>n,n){
        if(flag)cout<<endl;
        vector<data>V(n);
        for(int i=0;i<n;i++){
            string str;
            int w,l,d;
            cin>>str>>w>>l>>d;
            V[i]=data(str,i,w*3+d);
        }
        sort(V.begin(),V.end(),greater<data>());
        for(int i=0;i<n;i++){
            data d=V[i];
            cout<<d.str<<","<<d.p<<endl;
        }
        flag=true;
    }
}