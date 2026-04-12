#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;
    cin>>N>>M;
    int a[M],b[M];
    vector<vector<bool>> data(N,vector<bool>(N,false));
    for(int i=0;i<M;i++){
        cin>>a[i]>>b[i];
        data.at(a[i]-1).at(b[i]-1)=true;
    }
    vector<int> x(N-1);
    for(int i=0;i<N-1;i++){
        x.at(i)=i+1;
    }
    int ans=0;
    do{
        bool j=true;
        if(!data.at(0).at(x.at(0))) j=false;
        for(int i=0;i<N-2;i++){
            int m=min(x.at(i),x.at(i+1));
            int M=max(x.at(i),x.at(i+1));
            if(!data.at(m).at(M)){
                j=false;
            }
        }
        if(j) ans++;
    }while(next_permutation(x.begin(),x.end()));
    cout<<ans<<endl;
}