#include <bits/stdc++.h>
using namespace std;
long n,m;
vector<long[2]> var(28);
long f(vector<long> c,long t){
    c[t-1]=1;
    vector<long> conf(c.size(),1);
    if(c==conf)
        return 1;
    long count=0;
    for(auto x:var){
        if(x[0]==t&&c[x[1]-1]!=1)
            count+=f(c,x[1]);
        else if(x[1]==t&&c[x[0]-1]!=1)
            count+=f(c,x[0]);
    }
    return count;
}
int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++)
        cin>>var[i][0]>>var[i][1];
    long count=0;
    for(auto x:var){
        if(x[0]==1){
            vector<long> c(n,0);
            c[0]=1;
            count+=f(c,x[1]);
        }
    }
    cout<<count;
}