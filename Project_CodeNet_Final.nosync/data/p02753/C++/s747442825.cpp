#include<bits/stdc++.h>
using namespace std;

signed main(){
    char ch=getchar(),last;
    last=ch;
    
    for(int i=1;i<=2;++i){
        ch=getchar();
        if(ch!=last) return puts("Yes"),0;
        last=ch;
    }
    
    return puts("No"),0;
}