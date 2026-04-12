#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC70(void);
void ABC71(void);
void ABC72(void);
void ABC73(void);
void ABC74(void);
void ABC75(void);
void ABC76(void);
void ABC77(void);
void ABC78(void);
void ABC79(void);

int main(void){
    ABC78();
}

void ABC78(){
    int x,y,z,c=0;
    cin>>x>>y>>z;
    for(int i=0;x>0;i++){
        if(i==0){
            x-=y+2*z;
            if(x>=0)c++;
        }
        x-=y+z;
        if(x>=0)c++;
    }
    cout<<c<<endl;
}