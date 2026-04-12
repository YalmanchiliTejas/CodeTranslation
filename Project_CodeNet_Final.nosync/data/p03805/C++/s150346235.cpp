#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,ans=0;
    cin>>N>>M;
    vector<int> P(N);
    vector<set<int>> AB(N);
    for(int i=0;i<N;i++) P[i]=i;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        AB[a-1].insert(b-1), AB[b-1].insert(a-1);
    }
    do{
        for(int i=0;i<N-1;i++)
            if(AB[P[i]].count(P[i+1])==false) goto skip;
        ans++;
        skip:;
    }while(next_permutation(P.begin()+1,P.end()));
    cout<<ans<<endl;
}