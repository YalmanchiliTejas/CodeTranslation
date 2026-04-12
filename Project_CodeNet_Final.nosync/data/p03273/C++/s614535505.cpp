#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int H,W;
string a[100];

int main(){
    cin>>H>>W;
    rep(i,H) cin>>a[i];

    int r[100],c[100];
    fill(r,r+100,0);
    fill(c,c+100,0);
    rep(i,H){
        rep(j,W){
            if(a[i][j]=='#'){
                r[i]=1;
                c[j]=1;
            }
        }
    }

    rep(i,H){
        if(r[i]==1){
            rep(j,W){
                if(c[j]==1){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
}