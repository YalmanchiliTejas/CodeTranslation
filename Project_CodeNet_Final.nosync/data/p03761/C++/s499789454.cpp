//#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)//初期値a,i<bの範囲でループ
#define REP(i,n) FOR(i,0,n)//初期値0,i<nの範囲でループ
using namespace std;
typedef long long ll;//int64
typedef unsigned long long ull;

int n;
string s;
string ans;
int cnt[150];
int c[150];
int main(){
    //printf("%d",'z');
    cin>>n;
    REP(i,140)cnt[i]=1000000;
    REP(i,n){
        cin>>s;
        REP(j,150)c[j]=0;
        REP(j,s.size()){
            c[s[j]]++;
        }
        for(int j='a';j<='z';j++){
            cnt[j]=min(cnt[j],c[j]);
        }
        
        
    }
    for(int j='a';j<='z';j++){
        REP(k,cnt[j])ans+=j;
    }
    cout<<ans;
    

    return 0;
}