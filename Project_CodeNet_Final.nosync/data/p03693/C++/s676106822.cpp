#include <iostream>
using namespace std;
void ABC60(void);
void ABC61(void);
void ABC62(void);
void ABC63(void);
void ABC64(void);
void ABC65(void);
void ABC66(void);
void ABC67(void);
void ABC68(void);
void ABC69(void);

int main(void){
    ABC64();
}

void ABC64(void){
    int n,a,b,c;
    cin>>a>>b>>c;
    n=a*100+b*10+c;
    if(n%4==0)cout<<"YES";
    else cout<<"NO";
}