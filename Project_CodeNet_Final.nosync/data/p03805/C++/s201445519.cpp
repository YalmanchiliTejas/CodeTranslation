#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M,ans=0;
    cin >> N >> M;
    int graph[N][N];
    memset(graph,0,sizeof(graph));
    vector<int> ab(N-1);

    for(int i=0;i<N-1;i++){
        ab[i] = i+1;
    }

    for(int i=0;i<M;i++){
        int k,j;
        cin >> k >> j;
        k--;
        j--;
        graph[k][j] = 1; 
        graph[j][k] = 1;
    }

    do{
        if(graph[0][ab[0]]==1){
            for(int i=1;i<N-1;i++){
                if(graph[ab[i]][ab[i-1]]!=1){
                    break;
                }
                if(i==N-2){
                    ans++;
                }
            }
        }
    }while(next_permutation(ab.begin(),ab.end()));

    if(N==2 && M!=0){
        cout << 1 << endl;
    }else{
        cout << ans << endl;
    }
}