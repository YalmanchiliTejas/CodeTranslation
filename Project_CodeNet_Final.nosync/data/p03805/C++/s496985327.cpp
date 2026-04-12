#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool table[8][8];
int f(vector<bool>check,int n,int v){
    bool allcheck=true;
    for(int i=0;i<n;i++){
        if(!check[i]) allcheck=false;
    }
    if(allcheck) return 1;
 
    int res=0;
    for(int i=0;i<n;i++){
        if(table[v][i]==false) continue;
        if(check[i]) continue;
        check[i]=true;
        res+=f(check,n,i);
        check[i]=false;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    int m,n;
    cin>>n>>m;
 
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        table[a-1][b-1]=true;
        table[b-1][a-1]=true;
    }
    vector<bool> check(n);
    //bool check[8];
    for(int i=0;i<n;i++){
        check[i]=false;
    }
    check[0]=true;
 
    cout<<f(check,n,0)<<endl;
    return 0;
}