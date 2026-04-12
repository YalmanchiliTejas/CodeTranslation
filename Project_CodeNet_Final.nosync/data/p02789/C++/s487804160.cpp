#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef long long int ll;

template<class T> inline bool chmax(T& a,T b){ if(a<b){ a=b; return true;} return false; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){ a=b; return true;} return false; }

typedef pair<int,int> pair;

int main(){
    int n,m;
    cin >> n >> m;
    n-=m;
    if(n==0){
        puts("Yes");
    }else{
        puts("No");
    }
}