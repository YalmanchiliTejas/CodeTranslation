#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0;i<(int)n;i++)
struct edge{int from, to;};

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int count=0;
    x-=z;
    while(x>=y+z){
        count++;
        x-=y+z;
    }
    cout << count<<endl;
    return 0;
}