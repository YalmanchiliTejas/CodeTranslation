#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > flag(9,vector<int>(9,0));
vector<int> v;


int main(){
    int N,M;
    cin>>N>>M;
    int a[100],b[100];
    for(int i=0;i<M;i++){
        cin>>a[i]>>b[i];
        flag[a[i]][b[i]]=1;
        flag[b[i]][a[i]]=1;
    }

    for(int i=1;i<=N;i++){
        v.push_back(i);
    }
    int ans=0;
    do{
        int cnt=0;
        for(int i=0;i<N-1;i++){
            if(flag[v[i]][v[i+1]]) cnt++;
        }
        ans+=(cnt==N-1);
    }while(next_permutation(v.begin()+1,v.end()));

    cout<<ans<<endl;

        
}