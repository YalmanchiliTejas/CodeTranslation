#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin>>s;
    //s+=" ";
    int flag=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1] ){
            flag=1;break;
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}

