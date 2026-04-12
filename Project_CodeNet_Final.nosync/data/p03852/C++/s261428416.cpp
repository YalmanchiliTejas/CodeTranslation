#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <list> //list<???> a; a.push_back ,insert(追加したい要素),a.sort(),参照できない
#include <vector> //vector<???> a; a.push_back,sort(a.begin(),a.end());a[i]
//配列 int a[N];a[i]=追加したい要素;sort(a,a+N);a[i]
using namespace std;
typedef long  ll;
#define rep(i,n) for(int i=0;i<(n);i++)


//using namespace std;
//


int main(){
  string moji;cin>>moji;
  if (moji=="a" || moji=="i" || moji=="u" || moji=="e" || moji=="o"){
    cout<<"vowel"<<endl;

  }else{
    cout<<"consonant"<<endl;
  }
}