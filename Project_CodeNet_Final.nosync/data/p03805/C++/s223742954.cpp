#include<bits/stdc++.h>
using namespace std;

vector<int> g[15];

int main(){
    int N,M; cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int array[N];
    for(int i=0;i<N;i++) array[i]=i;

    int ans=0;
    do{
        bool flag=true;
        for(int i=0;i<N-1;i++){
            bool now=false;
            if(array[0]!=0){
                flag=false;
                break;
            }
            for(auto j:g[array[i]]){
                if(j==array[i+1]){
                    now=true;
                    break;
                }
            }
            if(now==false){
                flag=false;
                break;
            }

        }
        if(flag) ans++;
    }while(next_permutation(array,array+N));
    cout << ans << endl;
}