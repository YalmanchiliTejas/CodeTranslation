#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string S;
    cin>>S;
    int flg=0;
    for(int i=0;i<S.size()-1;i++){
        if(S[i]=='A'&&S[i+1]=='C')flg=1;
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}
