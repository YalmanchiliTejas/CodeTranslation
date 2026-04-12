#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<set>
#include<stdio.h>
using namespace std;


const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

#define rep(i,x) for(int i=0;i<x;i++)
#define re(i,x,y) for(int i=x;i<y;i++)


int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    int a[50][50]={0};
    rep(i,n){
        cin>>s[i];
    }
    int b[26]={0};
    rep(i,n){
        rep(k,s[i].size()){
            for(char l='a';l<='z';l++){
                if(s[i][k]==l){
                    a[i][l-'a']=a[i][l-'a']+1;
                }
            }
        }
    }
    
    for(int i=0;i<26;i++){
        int temp=100000;
        for(int k=0;k<n;k++){
            temp=min(a[k][i],temp);
        }
        b[i]=temp;
    }
    
    for(int i=0;i<26;i++){
        if(b[i]){
        while(b[i]){
            char c;
            c='a'+i;
            printf("%c",c);
            b[i]--;
        }
        }
    }
    return 0;
}