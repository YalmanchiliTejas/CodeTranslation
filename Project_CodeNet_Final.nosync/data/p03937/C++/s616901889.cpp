    #include<bits/stdc++.h>                                                                                           
    
    using namespace std;
    
    #define rep(i,n) for(int i=0;i<(n);++i)
    #define reps(i,n) for(int i=1;i<=(n);++i)
    #define all(x) (x).begin(),(x).end()
    #define int long long
    using pii = pair<int,int>;
    constexpr int INF  = 0x3f3f3f3f;
    constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
    
    char s[100][100];
    signed main(){
        int h,w;
        cin >> h >> w;
        reps(i,h){
            reps(j,w){
                cin >> s[i][j];
            }
        }
        pii now;
        now.first = 1;
        now.second = 1;
        while(!(now.first == h && now.second == w)){
            if(s[now.first][now.second + 1] != '#' && s[now.first + 1][now.second] != '#'){
                cout << "Impossible\n";
                return 0;
            }
            else if(s[now.first][now.second + 1] == '#' && s[now.first + 1][now.second] == '#'){
                cout << "Impossible\n";
                return 0;
            }
            else if(s[now.first][now.second-1] == '#'){
                cout << "Impossible\n";
                return 0;
            }
            else if(s[now.first -1][now.second] == '#'){
                cout << "Impossible\n";
                return 0;
            }
            else if(s[now.first][now.second + 1] == '#'){
                s[now.first][now.second] = '.';
                now.second++;
            }
            else{
                s[now.first][now.second] = '.';
                now.first++;
            }
        }
        if(s[h][w-1] == '#' || s[h-1][w] == '#') cout << "Impossible\n";
        else cout << "Possible\n";
        return 0;    
    }  