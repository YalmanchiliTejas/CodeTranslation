#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> G(N,vector<int>());
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<int> v(N-1);
    vector<int> road(N-1);
    for(int i=0;i<N-1;i++) v[i] = i+1; //1,2,3,....,N-1

    int count=0;
    do{
        bool ok = true;
        int pos = 0,next = 0;
        while(pos!=v[N-2]){
            auto itr = find(G[pos].begin(),G[pos].end(),v[next]);
            if(itr==G[pos].end()){ok=false;break;}
            else{pos = v[next]; next++;}
        }
        if(ok) count++;

    }while(next_permutation(v.begin(),v.end()));

    cout << count << endl;
}