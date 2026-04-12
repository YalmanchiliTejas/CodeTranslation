#include<bits/stdc++.h>
using namespace std;
int n;
string str;
string res;
map<char,char> o;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    cin>>str;
    res="";
    for(int i=0;i<n;i++)
        res+="?";
    o['S']='W';
    o['W']='S';
    res[0]='S';
    res[n-1]='S';
    while(1){
        bool flg=true;
        for(int i=0;i<n;i++){
            if(res[i]=='S'&&str[i]=='o'||res[i]=='W'&&str[i]=='x'){
                if(res[(i-1+n)%n]!=res[(i+1)%n]&&res[(i+1)%n]!='?')
                {	
                    flg=false;
                    break; 
                }
                res[(i+1)%n]=res[(i-1+n)%n];
            }
            else{
                if(res[(i-1+n)%n]==res[(i+1)%n]&&res[(i+1)%n]!='?')
                {
                    flg=false;
                    break; 
                }
                res[(i+1)%n]=o[res[(i-1+n)%n]];
            }
        }
        if(flg==true){
            cout<<res<<endl;
            return 0;
        }
        for(int i=1;i<n-1;i++)
            res[i]='?';
        if(res[0]=='S'&&res[n-1]=='S')
            res[n-1]='W';
        else if(res[0]=='S'&&res[n-1]=='W')
            res[n-1]='S',res[0]='W';
        else if(res[0]=='W'&&res[n-1]=='S')
            res[n-1]='W';
        else
            break;
    }
    cout<<-1;
    return 0;
}
