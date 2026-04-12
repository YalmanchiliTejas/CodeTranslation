#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;


int main() {
    int x,y,z;
    cin>>x>>y>>z;
    int count =0;
    x-=z;
    while(x>0){
        x-=y+z;
        if(x<0)break;
        count++;
    }
    cout<<count<<endl;
}