#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>

using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

//階乗
int factorial(int k){
    int result=1;
    for (int i=1;i<=k;++i){
        result*=i;
    }
    return result;
}


int main() {
    int h,w;
    cin>>h>>w;

    int sum=0;
    rep(i,h){
        rep(j,w){
            char a;
            cin>>a;

            if(a=='#')sum++;
        }
    }
    if(sum==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}


