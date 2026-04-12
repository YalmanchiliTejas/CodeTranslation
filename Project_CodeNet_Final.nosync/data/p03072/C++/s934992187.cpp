//124 B - Great Ocean View 2019/04/13
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i ,n) cin >> h[i];
    int __view=0;bool f[n]={false};f[0]=true;
    for(int i=n-1;i>0;--i){ 
        int j=i; 
        while(j>0){  
            if(h[i]<h[j-1]) break;
            --j;
        }
        if(j==0) f[i]=true;
    }
    rep(i ,n){
        if(f[i]) ++__view;
    }
    cout << __view << endl;
}
