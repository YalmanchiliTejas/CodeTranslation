#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(n==3){
        if(s=="ooo")cout<<"SSS"<<endl;
        else if(s=="xxx")cout<<"WWW"<<endl;
        else cout<<"-1"<<endl;
        return 0;
    }
    for(int j=0;j<4;j++){
        vector<char>x(n);
        int last;
        if(j==0){
            x[0]='S';
            x[1]='S';
            if(s[0]=='o')last='S';
            else last='W';
        }
        if(j==1){
            x[0]='S';
            x[1]='W';
            if(s[0]=='o')last='W';
            else last='S';
        }
        if(j==2){
            x[0]='W';
            x[1]='S';
            if(s[0]=='o')last='W';
            else last='S';
        }
        if(j==3){
            x[0]='W';
            x[1]='W';
            if(s[0]=='o')last='S';
            else last='W';
        }
        for(int i=0;i<n-1;i++){
            if(x[i]=='S' && x[i-1]=='S' && s[i]=='o')x[i+1]='S';
            if(x[i]=='S' && x[i-1]=='S' && s[i]=='x')x[i+1]='W';
            if(x[i]=='S' && x[i-1]=='W' && s[i]=='o')x[i+1]='W';
            if(x[i]=='S' && x[i-1]=='W' && s[i]=='x')x[i+1]='S';
            if(x[i]=='W' && x[i-1]=='S' && s[i]=='o')x[i+1]='W';
            if(x[i]=='W' && x[i-1]=='S' && s[i]=='x')x[i+1]='S';
            if(x[i]=='W' && x[i-1]=='W' && s[i]=='o')x[i+1]='S';
            if(x[i]=='W' && x[i-1]=='W' && s[i]=='x')x[i+1]='W';
        }
             if(x[n-1]=='S' && x[n-2]=='S' && s[n-1]=='o' && x[0]=='W')continue;
        else if(x[n-1]=='S' && x[n-2]=='S' && s[n-1]=='x' && x[0]=='S')continue;
        else if(x[n-1]=='S' && x[n-2]=='W' && s[n-1]=='o' && x[0]=='S')continue;
        else if(x[n-1]=='S' && x[n-2]=='W' && s[n-1]=='x' && x[0]=='W')continue;
        else if(x[n-1]=='W' && x[n-2]=='S' && s[n-1]=='o' && x[0]=='S')continue;
        else if(x[n-1]=='W' && x[n-2]=='S' && s[n-1]=='x' && x[0]=='W')continue;
        else if(x[n-1]=='W' && x[n-2]=='W' && s[n-1]=='o' && x[0]=='W')continue;
        else if(x[n-1]=='W' && x[n-2]=='W' && s[n-1]=='x' && x[0]=='S')continue;
        else if(x[0]=='S' && x[1]=='S' && s[0]=='o' && x[n-1]=='W')continue;
        else if(x[0]=='S' && x[1]=='S' && s[0]=='x' && x[n-1]=='S')continue;
        else if(x[0]=='S' && x[1]=='W' && s[0]=='o' && x[n-1]=='S')continue;
        else if(x[0]=='S' && x[1]=='W' && s[0]=='x' && x[n-1]=='W')continue;
        else if(x[0]=='W' && x[1]=='S' && s[0]=='o' && x[n-1]=='S')continue;
        else if(x[0]=='W' && x[1]=='S' && s[0]=='x' && x[n-1]=='W')continue;
        else if(x[0]=='W' && x[1]=='W' && s[0]=='o' && x[n-1]=='W')continue;
        else if(x[0]=='W' && x[1]=='W' && s[0]=='x' && x[n-1]=='S')continue;
        else{
            for(int i=0;i<n;i++)cout<<x[i];
            cout<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}