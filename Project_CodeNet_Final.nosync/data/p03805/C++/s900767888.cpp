#include<bits/stdc++.h>

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> hen(n,std::vector<bool>(n));
    for(int i = 0; i < m; i++){
        int a,b; std::cin >> a >> b; a--; b --;
        hen[a][b] = true;
        hen[b][a] = true;
    }
    int cnt = 0;
    std::vector<int> path(n);
    std::iota(path.begin(),path.end(),0);
    do{
        if(path[0] != 0)continue;
        bool res = true;
        for(int i = 1; i < n; i++){
            if(!hen[path[i - 1]][path[i]])res = false;
        }
        if(res)cnt++;
    }while(std::next_permutation(path.begin(),path.end()));
    std::cout << cnt << std::endl;
}