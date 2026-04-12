#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = long long;
using P = std::tuple<int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int N, M;
int xs[200100], ys[200100];
vector<int> G[400100], v, w;

// B..B R ([RB]*) R pattern
ll compute1(){
    ll res = std::numeric_limits<ll>::max() / 2;
    
    int single_n = 0, double_n = 0;
    for(int i=0;i+1<M;++i){
        bool doesExistSingle = false;
        int loop_n = 0;
        for(int to : G[i]){
            if(to == i){
                ++loop_n;
                continue;
            }
            
            if(to < i){
                --single_n;
                ++double_n;
            }else{
                doesExistSingle = true;
                ++single_n;
            }
        }

        loop_n /= 2;
        double_n += loop_n;

        // std::cout << i << ": " << single_n << ", " << double_n << std::endl;

        if(loop_n == 0 && !doesExistSingle){
            break;
        }
        
        if(double_n == 0){
            res = min(res, 1ll * (w[N-1] - v[0]) * (v[M-1] - v[i+1]));
        }else{
            res = min(res, 1ll * (w[N-1] - v[0]) * (v[M-1] - v[i]));
        }
        
        if(double_n > 0){
            break;
        }
    }

    return res;
}

int _count(int i, int l, int r){
    int res = 0, loop_n = 0;
    for(int to : G[i]){
        if(to == i){
            ++loop_n;
            continue;
        }
        if(l <= to && to <= r){
            
        }else{
            ++res;
        }
    }

    loop_n /= 2;
    res += loop_n;

    return res;
}

// B..B R ([RB]*) R B..B pattern
ll compute2(){
    int l = 0, r = M - 1;
    
    {
        int single_n = 0, double_n = 0;
        while(l < M){
            int loop_n = 0;
            for(int to : G[l]){
                if(to == l){
                    ++loop_n;
                    continue;
                }

                if(to < l){
                    --single_n;
                    ++double_n;
                }else{
                    ++single_n;
                }
            }

            loop_n /= 2;
            double_n += loop_n;
            
            if(double_n > 0){
                break;
            }

            ++l;
        }
    }

    {
        int single_n = 0, double_n = 0;
        while(r >= 0){
            int loop_n = 0;
            for(int to : G[r]){
                if(to == r){
                    ++loop_n;
                    continue;
                }

                if(r < to){
                    --single_n;
                    ++double_n;
                }else{
                    ++single_n;
                }
            }

            loop_n /= 2;
            double_n += loop_n;

            if(double_n > 0){
                break;
            }

            --r;
        }
    }

    if(l > r){swap(l, r);}

    int hr = upper_bound(G[0].begin(), G[0].end(), r) - G[0].begin() - 1,
        lr = upper_bound(G[M-1].begin(), G[M-1].end(), r) - G[M-1].begin() - 1,
        hl = lower_bound(G[0].begin(), G[0].end(), l) - G[0].begin(),
        lll = lower_bound(G[M-1].begin(), G[M-1].end(), l) - G[M-1].begin();
    hr = hr >= 0 ? G[0][hr] : 252521 * 2;
    lr = lr >= 0 ? G[M-1][lr] : 252521 * 2;
    hl = hl < G[0].size() ? G[0][hl] : 252521 * 2;
    lll = lll < G[M-1].size() ? G[M-1][lll] : 252521 * 2;
    
    int ls[4] = {0, hr, lr, max(hr, lr) < 252521 * 2 ? min(hr, lr) : 252521 * 2}, rs[4] = {0, hl, lll, max(hl, lll) < 252521 * 2 ? max(hl, lll) : 252521 * 2};

    ll res = std::numeric_limits<ll>::max() / 2;
    for(int i=1;i<4;++i){
        for(int j=1;j<4;++j){
            int _l = min(l, ls[i]), _r = max(r, rs[j]);
            if(_l == 252521 * 2 || _r == 252521 * 2 || (i | j) != 3){
                continue;
            }

            int edge_in_lr_n = 0, blue_n = 0;
            for(int k=_l;k<=_r;++k){
                for(int to : G[k]){
                    if(_l <= to && to <= _r){
                        ++edge_in_lr_n;
                    }else{
                        ++blue_n;
                    }
                }               
            }

            edge_in_lr_n /= 2;
            blue_n += edge_in_lr_n;
            
            int cl = 0, cr = 0;
            if(_l - 1 >= 0){
                cl = _count(_l - 1, _l, _r);
            }
            if(_r + 1 < M){
                cr = _count(_r + 1, _l, _r);
            }
        
            while(blue_n < N){
                if(cl > cr){
                    blue_n += cl;
                    --_l;
                    if(_l - 1 >= 0){
                        cl = _count(_l - 1, _l, _r);
                    }else{
                        cl = 0;
                    }
                }else{
                    blue_n += cr;
                    ++_r;
                    if(_r + 1 < M){
                        cr = _count(_r + 1, _l, _r);
                    }else{
                        cr = 0;
                    }
                }
            }

            res = min(res, 1ll * (v[M-1] - v[0]) * (v[_r] - v[_l]));
        }
    }

    return res;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    
    v.resize(2 * N);
    w.resize(N);
    for(int i=0;i<N;++i){
        std::cin >> xs[i] >> ys[i];
        v[i * 2 + 0] = xs[i];
        v[i * 2 + 1] = ys[i];
        w[i] = min(xs[i], ys[i]);
    }

    sort(w.begin(), w.end());
    
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    
    M = v.size();
    
    for(int i=0;i<N;++i){
        int x = lower_bound(v.begin(), v.end(), xs[i]) - v.begin(),
            y = lower_bound(v.begin(), v.end(), ys[i]) - v.begin();
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    sort(G[0].begin(), G[0].end());
    sort(G[M-1].begin(), G[M-1].end());
    
    ll c1 = compute1(), c2 = compute2();
    // std::cout << c1 << ", " << c2 << std::endl;
    ll res;
    if(G[0].size() == 1 && G[0][0] == M - 1){
        res = c1;
    }else{
        res = min(c1, c2);
    }
    
    std::cout << res << std::endl;
}


