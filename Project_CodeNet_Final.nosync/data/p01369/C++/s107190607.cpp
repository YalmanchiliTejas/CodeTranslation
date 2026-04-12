#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main(){
    string str;
    int c[26];
    fill(c,c+26,1);
    for(int i=7;i<=15;i++)c[i]=-1;
    c['u'-'a']=c['y'-'a']=-1;
    while(cin>>str,str!="#"){
        int cnt=0;
        for(int i=0;i<str.length()-1;i++){
            if(c[str[i]-'a']*c[str[i+1]-'a']<0)cnt++;
        }
        cout<<cnt<<endl;
    }
}