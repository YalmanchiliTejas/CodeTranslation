#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> H, W;
string Area[4];

int d[1<<16];

int main(){
    cin >> N;
    H.resize(N); W.resize(N);
    for(int i=0; i<N; i++)
        cin >> H[i] >> W[i];
    
    vector<set<int>> edges(N);
    for(int k=0; k<N; k++){
        for(int h=-4; h<=4; h++){
            for(int w=-4; w<=4; w++){
                int t = 0;
                for(int i=0; i<H[k]; i++){
                    for(int j=0; j<W[k]; j++){
                        int nh = h+i;
                        int nw = w+j;
                        if(0<=nh && nh<4 && 0<=nw && nw<4){
                            t |= 1<<(4*nh + nw);
                        }
                    }
                }
                edges[k].insert(t);
            }
        }
    }
    
    int RGB[3] = {};
    for(int i=0; i<4; i++){
        cin >> Area[i];
        for(int j=0; j<4; j++){
            if(Area[i][j] == 'R')
                RGB[0] |= (1<<(4*i + j));
            if(Area[i][j] == 'G')
                RGB[1] |= (1<<(4*i + j));
            if(Area[i][j] == 'B')
                RGB[2] |= (1<<(4*i + j));
        }
    }
    
    queue<int> que;
    memset(d, -1, sizeof(d));
    d[0] = 0;
    que.push(0);
    
    while(!que.empty()){
        auto x = que.front(); que.pop();
        
        for(int i=0; i<N; i++){
            for(auto v: edges[i]){
                for(int j=0; j<3; j++){
                    int y = x;
                    for(int k=0; k<3; k++){
                        if(j == k){
                            y |= RGB[k] & v;
                        }else{
                            y &= ~(RGB[k] & v);
                        }
                    }
                    if (d[y] < 0){
                        que.push(y);
                        d[y] = d[x] + 1;
                        if(y == (RGB[0] | RGB[1] | RGB[2])){
                            cout << d[y] << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}