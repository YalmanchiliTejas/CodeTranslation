    #include <bits/stdc++.h>
    using namespace std;
     
    const int N = 9;
     
    int n, m;
    char a[N][N];
     
    int main(){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", a[i]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int x = i + 1; x < n; x++){
                    for(int y = 0; y < j; y++){
                        if(a[i][j] == '#' && a[x][y] == '#'){
                            puts("Impossible");
                            return 0;
                        }
                    }
                }
            }
        }
        puts("Possible");
    }