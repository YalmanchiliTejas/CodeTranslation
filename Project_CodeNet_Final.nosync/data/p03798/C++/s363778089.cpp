#include <iostream>
#include <string>
using namespace std;
int n;
string str;
bool flag;

int solve(string s,char s0, char s1){
    char prev=s0,temp=s1,next;
    if(flag)cout<<prev;
    for(int i=1; i<s.size();i++){
        if(temp=='S')
            if(s[i]=='o' && prev=='S')next='S';
            else if(s[i]=='o' && prev=='W')next='W';
            else if(s[i]=='x' && prev=='S')next='W';
            else next='S';
        else{
            if(s[i]=='o' && prev=='S')next='W';
            else if(s[i]=='o' && prev=='W')next='S';
            else if(s[i]=='x' && prev=='S')next='S';
            else next='W';
        }
        if(flag)cout<<temp;
        prev=temp; 
        temp=next;
    }
    if(next != s0)return 0;
    if(s0=='S' && s1=='S' && prev=='S' && s[0]=='o')return 1;
    else if(s0=='S' && s1=='W' && prev=='W' && s[0]=='o')return 1;
    else if(s0=='S' && s1=='S' && prev=='W' && s[0]=='x')return 1;
    else if(s0=='S' && s1=='W' && prev=='S' && s[0]=='x')return 1;
    else if(s0=='W' && s1=='S' && prev=='W' && s[0]=='o')return 1;
    else if(s0=='W' && s1=='W' && prev=='S' && s[0]=='o')return 1;
    else if(s0=='W' && s1=='W' && prev=='W' && s[0]=='x')return 1;
    else if(s0=='W' && s1=='S' && prev=='S' && s[0]=='x')return 1;
    else return 0;
}


int main(void){
    cin>>n>>str;
    flag=solve(str,'S','S');
    if(flag){ flag=solve(str,'S','S'); return 0;}
    flag=solve(str,'S','W');
    if(flag){ flag=solve(str,'S','W'); return 0;}
    flag=solve(str,'W','S');
    if(flag){ flag=solve(str,'W','S'); return 0;}
    flag=solve(str,'W','W');
    if(flag){ flag=solve(str,'W','W'); return 0;}
    cout<<-1<<endl;
    return 0;
}
