#include<bits/stdc++.h>
using namespace std;
int se(char s){
    int r;
    if(s=='a'||s=='t'||s=='g'||s=='r'||s=='f'||s=='v'||s=='c'||s=='e'||s=='d'||s=='s'||s=='w'||s=='x'||s=='q'||s=='z'||s=='b')r=1;
    else r=0;
    return r;
}
int main(){
    string s;
    int i,r,j,sum;
    while(cin>>s,s!="#"){
    j=se(s[0]);
    sum=0;
    for(int i=1;i<s.size();i++){
        r=se(s[i]);
        if(j!=r){sum++;
        j=r;}
    }
    cout<<sum<<endl;
    }
    return 0;
}
 