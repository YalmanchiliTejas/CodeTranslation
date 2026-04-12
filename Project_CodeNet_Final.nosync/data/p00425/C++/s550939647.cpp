#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    string an;
    int men[6],A,n,m1,m2;
    while(1){
        A=1;
        for(int i=0;i<6;i++){
            men[i]=i+1;
        }
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>an;
            if(an[0]=='N'){
                m1=men[0];men[0]=men[1];
                m2=men[4];men[4]=m1;
                m1=men[5];men[5]=m2;men[1]=m1;
                 A+=men[0];
            }else if(an[0]=='E'){
                m1=men[0];men[0]=men[3];
                m2=men[2];men[2]=m1;
                m1=men[5];men[5]=m2;men[3]=m1;
                 A+=men[0];
            }else if(an[0]=='W'){
                m1=men[0];men[0]=men[2];
                m2=men[3];men[3]=m1;
                m1=men[5];men[5]=m2;men[2]=m1;
                 A+=men[0];
            }else if(an[0]=='S'){
                m1=men[0];men[0]=men[4];
                m2=men[1];men[1]=m1;
                m1=men[5];men[5]=m2;men[4]=m1;
                A+=men[0];
            }else if(an[0]=='R'){
                m1=men[2];men[2]=men[4];
                m2=men[1];men[1]=m1;
                m1=men[3];men[3]=m2;men[4]=m1;
                 A+=men[0];
            }else if(an[0]=='L'){
                m1=men[2];men[2]=men[1];
                m2=men[4];men[4]=m1;
                m1=men[3];men[3]=m2;men[1]=m1;
                 A+=men[0];
            }
        }
        cout<<A<<"\n";
    }
}