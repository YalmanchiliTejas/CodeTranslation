#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

char s[101][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char com[8];
    int p, p2;
    char c;
    int ss[101]={};
    while(true){
        cin>>com;
        if(com[0]=='q') break;
        else if(com[0]=='m'){
            cin>>p>>p2;
            s[p2][ss[p2]++]=s[p][--ss[p]];
        } else if(com[1]=='o'){
            cin>>p;
            cout<<s[p][--ss[p]]<<'\n';
        } else if(com[1]=='u'){
            cin>>p>>c;
            s[p][ss[p]++]=c;
        }
    }
    
    return 0;
}