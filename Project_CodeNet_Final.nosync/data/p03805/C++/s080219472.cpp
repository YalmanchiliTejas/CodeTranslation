#include <bits/stdc++.h>
using namespace std;
int V,E;
int m[9][9];
int cnt,b;
void f(int x){
    b+=(1<<x);
    if(b==(1<<V)-1){
        cnt++;
    }
    else{
        for(int i=0;i<V;i++){
            if(m[x][i]&&(b&(1<<i))==0){
                f(i);
            }
        }
    }
    b-=(1<<x);
}
int main(){
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        m[x][y]=m[y][x]=1;
    }
    f(0);
    cout<<cnt<<endl;
    return 0;
}
