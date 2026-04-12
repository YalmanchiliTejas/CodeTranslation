#include <iostream>
using namespace std;
void ABC150(void);
void ABC151(void);
void ABC152(void);
void ABC153(void);
void ABC154(void);
void ABC155(void);
void ABC156(void);
void ABC157(void);
void ABC158(void);
void ABC159(void);

int main(void){
    ABC158();
}

void ABC158(){
    string s;
    cin>>s;
    int k=0;
    if(s[0]==s[1])++k;
    if(s[0]==s[2])++k;
    if(s[2]==s[1])++k;
    if(k==3)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}