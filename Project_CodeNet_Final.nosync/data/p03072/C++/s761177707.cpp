#include <bits/stdc++.h>
#include <math.h>
int n,m,i,j,k,count1=0,count2=0;
using namespace std;
void ABC120(void);
void ABC121(void);
void ABC122(void);
void ABC123(void);
void ABC124(void);
void ABC125(void);
void ABC126(void);
void ABC127(void);
void ABC128(void);
void ABC129(void);

int main(void){
    ABC124();
}

void ABC124(){
    cin>>n;
    int max=0,h;
    for(i=0;i<n;i++){
        cin>>h;
        if(h>=max){
            max=h;
            count1++;
        }
    }
    cout<<count1<<endl;
}