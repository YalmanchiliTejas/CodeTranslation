#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int dh[2]={1, 0};
const int dw[2]={0, 1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    for(int h=0; h<H; h++) {
        cin >> field[h];
    }
    
    vector<vector<bool> > seen(H, vector<bool>(W, false));
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    bool flag=true;
    while(!que.empty()) {
        if(que.size()>1) {
            flag = false;
            break;
        }
        pair<int, int> cur;
        cur = que.front(); que.pop();
        seen[cur.first][cur.second] = true;

        bool break_or_not=false;
        if(cur.first>0) {
            for(int w=cur.second; w<W; w++) {
                if(field[cur.first-1][w]=='#' && !seen[cur.first-1][w]) {
                    flag = false;
                    break_or_not = true;
                    break;
                }
            }
        }
        if(break_or_not) break;
        if(cur.second>0) {
            for(int h=cur.first; h<H; h++) {
                if(field[h][cur.second-1]=='#' && !seen[h][cur.second-1]) {
                    flag = false;
                    break_or_not = true;
                }
            }
        }
        if(break_or_not) break;
        
        for(int i=0; i<2; i++) {
            int nh=cur.first+dh[i];
            int nw=cur.second+dw[i];
            
            if(nh>=H || nw>=W) continue;
            if(field[nh][nw]=='.') continue;
            if(seen[nh][nw]) continue;
            
            que.push(make_pair(nh, nw));
        }
        
        if((cur.first!=H-1 || cur.second!=W-1) && que.empty()) {
            flag = false;
        }
    }
    
    if(flag) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }


    return 0;
    
}