#include<bits/stdc++.h>
using ll = int_fast64_t;

int main(){
        int n, m;
        scanf("%d %d", &n, &m);
        std::vector<int> v(n);
        for(int i=0; i<n; i++) v[i] = i;

        int path[n][n];
        for(int i=0; i<n*n; i++) path[i/n][i%n] = 0;
        for(int i=0; i<m; i++){
                int a, b;
                scanf("%d %d", &a, &b);
                path[a-1][b-1] = path[b-1][a-1] = 1;
        }

        int ans = 0;
        do{
                if(v[0]!=0) continue;
                bool cant = false;
                for(int i=1; i<n; i++){
                        if(!path[v[i-1]][v[i]]) cant = true;
                }
                if(!cant) ans++;
        }while(std::next_permutation(v.begin(), v.end()));
        printf("%d\n", ans);
        return 0;
}