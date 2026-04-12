#include<bits/stdc++.h>
using ll = long long;

int main(){
        ll h, w;
        scanf("%lld %lld", &h, &w);
        std::vector<std::vector<ll>> mp(h+2, std::vector<ll>(w+2, 0));

        for(ll i=0; i<h; i++){
                std::string s;
                std::cin >> s;
                for(ll j=0; j<w; j++) mp[i+1][j+1] = (s[j]=='#');
        }

        std::vector<std::vector<bool>> used(h+2, std::vector<bool>(w+2, 0));
        std::queue<std::pair<ll,ll>> que;
        que.push({1,1});
        while(!que.empty()){
                ll x, y;
                std::tie(x,y) = que.front();
                que.pop();
                used[x][y] = 1;

                bool flag = 0;
                if(mp[x-1][y]&&used[x-1][y]==0 || mp[x][y-1]&&used[x][y-1]==0) flag = 1;
                if(mp[x+1][y] && mp[x][y+1]) flag = 1;
                if(flag){
                        puts("Impossible");
                        return 0;
                }

                if(mp[x+1][y]) que.push({x+1, y});
                if(mp[x][y+1]) que.push({x, y+1});
        }
        puts("Possible");
        return 0;
}