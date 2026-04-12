#include <bits/stdc++.h>
using namespace std;
    int main(){
        int N,M;cin>>N>>M;

    vector<vector<bool>> v(N,vector<bool> (N));

    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        v[a][b]=v[b][a]=true;

    }

    vector<int> num(N);
    iota(num.begin(),num.end(),0);
    int res=0;

    do{
        if(num[0]!=0)break;
        bool ok=true;
        for(int i=0;i+1<N;i++){
            
            int from=num[i];
            int to=num[i+1];
            if(v[from][to]!=true)ok=false;
        }
        if(ok)res++;
        }while(next_permutation(num.begin(),num.end()));

        cout<<res<<endl;
    }




