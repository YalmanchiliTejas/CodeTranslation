#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct state{
    vector<vector<char>> F;
    int x,y;
    bool operator<(const state& r)const{
        return F<r.F;
    }
};

int main(){
    int H,W;
    cin >> H >> W;
    set<state> s;
    vector<vector<char>> init(H,vector<char>(W,'.'));
    init[0][0] = '#';
    s.insert({init,0,0});
    for(int i=0;i<H+W-2;i++){
        set<state> ns;    
        for(auto now:s){
            if(now.x+1<H){
                now.F[now.x+1][now.y] = '#';
                now.x++;
                ns.insert(now);
                now.F[now.x][now.y] = '.';
                now.x--;
            }
            if(now.y+1<W){
                now.F[now.x][now.y+1] = '#';
                now.y++;
                ns.insert(now);
                now.F[now.x][now.y] = '.';
                now.y--;
            }
        }
        s = ns;
    }
    vector<vector<char>> A(H,vector<char>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin >> A[i][j];
    cout << (s.count({A,H-1,W-1})? "Possible":"Impossible") << endl;
}