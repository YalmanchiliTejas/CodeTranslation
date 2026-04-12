#include <bits/stdc++.h>
using namespace std;

int main(void){
    map<char,bool> right;
    right['y']=right['u']=right['i']=right['o']=right['p']=
    right['h']=right['j']=right['k']=right['l']=
    right['n']=right['m']=true;

    int cnt=0;
    char now=getchar(),before;
    while(before=now,now=getchar(),before!='#'){
        if(now=='\n'){
            cout<<cnt<<endl;
            cnt=0;
            now=getchar();
        }else if(right[before]^right[now]){
            cnt++;
        }
    }

    return 0;
}