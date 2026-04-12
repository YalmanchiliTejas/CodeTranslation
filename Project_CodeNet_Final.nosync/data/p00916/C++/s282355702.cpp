#include <bits/stdc++.h>
#define range(i, a, n) for(int (i) = (a); (i) < (n); (i)++)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

void compress(vi const& vec, map<int, int>& zip, vi& unzip){
    unzip = vec;

    sort(begin(unzip), end(unzip));
    unzip.erase(unique(begin(unzip), end(unzip)), unzip.end());

    rep(i, unzip.size()) zip[unzip[i]] = 2 * i + 1;
}

using Rect = tuple<int, int, int, int>;

int w, h;
vvi field;

vi dx = { 1, 0,-1, 0};
vi dy = { 0,-1, 0, 1};

void dfs(int y, int x){
    if(field[y][x] == 0) field[y][x] = 1;
    else return;

    rep(i, 4){
        int ny = y + dy[i], nx = x + dx[i];

        if(ny < 0 or h <= ny or
           nx < 0 or w <= nx) continue;

        dfs(ny, nx);
    }
}

int main(void){
    for(int n; cin >> n, n;){
        vi xs, ys;
        vector<Rect> rects(n);
        rep(i, n){
            int l, a, r, b; cin >> l >> b >> r >> a;
            rects[i] = tie(l, a, r, b);

            xs.push_back(l); xs.push_back(r);
            ys.push_back(a); ys.push_back(b);
        }

        vi unzip_x, unzip_y;
        map<int, int> zip_x, zip_y;

        compress(xs, zip_x, unzip_x);
        compress(ys, zip_y, unzip_y);

        for(auto & e : rects){
            int l, a, r, b;
            tie(l, a, r, b) = e;

            l = zip_x[l], r = zip_x[r];
            a = zip_y[a], b = zip_y[b];

            e = tie(l, a, r, b);
        }

        w = 501, h = 501;
        field = vvi(h, vi(w));
        for(auto & e : rects){
            int l, a, r, b;
            tie(l, a, r, b) = e;

            range(y, a, b + 1){
                field[y][l] = field[y][r] = 1;
            }
            range(x, l, r + 1){
                field[a][x] = field[b][x] = 1;
            }
        }

        int res = 0;
        rep(y, h){
            rep(x, w){
                if(field[y][x] == 0){
                    dfs(y, x);
                    res++;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}