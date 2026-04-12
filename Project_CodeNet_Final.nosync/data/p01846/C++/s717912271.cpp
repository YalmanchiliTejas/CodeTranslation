#include<iostream>
#include<vector>

using namespace std;

int main(){

    while(1){
        string s;
        cin>> s;
        if(s=="#") break;

        int sy, sx, gy, gx;
        cin>> sy>> sx>> gy>> gx;
        s+='/';
        int m=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='/') m++;
        }
        vector<char> a[m];
        int k=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='b'){
                a[k].push_back(s[i]);
            }else if(s[i]=='/'){
                a[k].push_back('b');
                k++;
            }else{
                for(int j=0; j<s[i]-'0'; j++){
                    a[k].push_back('.');
                }
            }
        }
        a[sy-1][sx-1]='.';
        a[gy-1][gx-1]='b';
        string t;
        for(int i=0; i<m; i++){
            int d=0;
            for(int j=0; j<a[i].size(); j++){
                if(a[i][j]=='b'){
                    if(d>0) t+=(char)(d+'0');
                    if(j!=a[i].size()-1) t+='b';
                    d=0;
                }else{
                    d++;
                }
            }
            t+='/';
        }

        t.pop_back();
        cout<< t<< endl;
    }

    return 0;
}