/**********

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*********/

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}

long long primechk[10000];

void preprocess(long long N){
    long long i,j;
    for(i=2;i<=N;i++){
        primechk[i]=1;
    }
    for(i=2;i<=N;i++){
        if(primechk[i]==1){
            for(j=2;i*j<=N;j++){primechk[i*j]=0;}
        }
    }
}

long long Binexpo(long long a,long long b){
    if(b==0)
        return 1;
    long long res=Binexpo(a,b/2);
    if(b%2){return res*res*a;}
    else{return res*res;}
}
long long Pwr(long long a,long long b,long long m){
    a%=m;
    long long res=1;
    while(b>0){
        if(b%2){res=res*a%m;}
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int main()
{   long long a,b,c,d,e,f,g,h,i,j,k,x,y,z,sum,cnt=0;
    char ch;
    cin>>ch;
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){cout<<"vowel";}
    else{cout<<"consonant";}

    return 0;
}