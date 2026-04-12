#include <stdio.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<vector>

using namespace std;

int nx[]={0,1,0,-1};
int ny[]={0,1,0,-1};
//*****************************************

int N,K,i;
char key;


int main(void){
    cin >> N ;
    char S[N];
    scanf("%s",S);
    cin >> K;

    key=S[K-1];

    for(i=0;i<N;i++)
    {
        if(S[i]!=key)S[i]='*';
    }


    printf("%s",S);

    return 0;
}



