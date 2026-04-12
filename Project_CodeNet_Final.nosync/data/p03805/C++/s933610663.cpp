#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mem[12],ab[12][12],cnt=0;
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)mem[i]=i+1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ab[a][b]=ab[b][a]=1;
    }
    do{
        bool b=true;
        for(int i=1;i<n;i++){
            if(ab[mem[i-1]][mem[i]]==0)b=false;
        }
        if(b)cnt++;
    }while(next_permutation(mem+1,mem+n));
    cout<<cnt<<endl;
    system("PAUSE");
}