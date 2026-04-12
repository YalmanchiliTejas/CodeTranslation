#include<bits/stdc++.h>
using namespace std;
char s[10010];
int main(){   
    gets(s+1);
    for(int i=1;s[i]!='\0';i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}