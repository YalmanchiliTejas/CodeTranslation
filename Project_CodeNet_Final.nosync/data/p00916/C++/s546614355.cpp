#include<bits/stdc++.h>
using namespace std;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};


void dfs(int i, int j, vector<vector<bool> > &Map){

    Map[i][j] = false;
    for(int h = 0; h < 4; h++){
        int ni = i + di[h];
        int nj = j + dj[h];        
        if(Map[ni][nj]) dfs(ni, nj, Map);
    }
}

int solve(int n){

    vector<int> X;
    vector<int> Y;
    vector<int> l(n);
    vector<int> t(n);
    vector<int> r(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> l[i] >> t[i] >> r[i] >> b[i];
        l[i] *= 2 + 2;
        t[i] *= 2 + 2;
        r[i] *= 2 + 2;
        b[i] *= 2 + 2;        
        X.push_back(l[i]);
        X.push_back(r[i]);
        Y.push_back(t[i]);
        Y.push_back(b[i]);
        
        X.push_back(l[i] + 1);
        X.push_back(l[i] - 1);        
        X.push_back(r[i] + 1);
        X.push_back(r[i] - 1);        
        Y.push_back(t[i] + 1);
        Y.push_back(t[i] - 1);        
        Y.push_back(b[i] + 1);
        Y.push_back(b[i] - 1);
        
    }

    //座標の始点、終点を追加
    X.push_back(0);
    X.push_back(-1);
    X.push_back(-2);            
    Y.push_back(0);
    Y.push_back(-1);
    Y.push_back(-2);            
    X.push_back(10000000);
    Y.push_back(10000000);

    //定石
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    // X = {0, 1, 1, 4, 4, 6, 9, 9, 10, 10, 10, 10}
    // Y = {0, 1, 1, 4, 4, 5, 6, 8, 8, 10, 10, 10}


    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    // X = {0, 1, 4, 6, 9, 10}
    // Y = {0, 1, 4, 5, 6, 8, 10}        
    
    int h = lower_bound(Y.begin(),Y.end(),10000000) - Y.begin();
    int w = lower_bound(X.begin(),X.end(),10000000) - X.begin();
    
    vector<vector<bool> > Map(h + 2, vector<bool> (w + 2, true));
    for(int i = 0; i <= h + 1; i++){
        Map[i][0] = Map[i][w + 1] = false;
    }
    for(int j = 0; j <= w + 1; j++){
        Map[0][j] = Map[h + 1][j] = false;
    }

    for(int i = 0; i < n; i++){

        int _l = lower_bound(X.begin(),X.end(),l[i]) - X.begin();
        int _r = lower_bound(X.begin(),X.end(),r[i]) - X.begin();

        int _b = lower_bound(Y.begin(),Y.end(),b[i]) - Y.begin();
        int _t = lower_bound(Y.begin(),Y.end(),t[i]) - Y.begin();

        for(int i = _b; i <= _t; i++){
            Map[i][_l] = Map[i][_r] = false;
        }

        for(int j = _l; j <= _r; j++){
            Map[_t][j] = Map[_b][j] = false;
        }

    }

    int ans = 0;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(Map[i][j]){
                dfs(i, j, Map);
                ans++;
            }
            //cout << Map[i][j] << " ";
        }
        //cout << endl;
    }

    return ans;
}

int main(){

    while(1){
        int n; cin >> n;
        if(!n) break;

        cout << solve(n) << endl;
    }

    return 0;
}
