#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

#define all(c) c.begin(),c.end()
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

typedef long long ll;
typedef vector<int> vi;


template<typename T,typename S>
ostream& operator<<(ostream& os,const pair<T,S>& val){
    os << "(" << val.first << "," << val.second << ")";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& val){
    os << "[ ";
    for(typename vector<T>::const_iterator it=val.begin();
        it != val.end();++it){
        os << *it << " ";
    }
    os << "]";
    return os;
}

#define mp(a,b) make_pair(a,b)

typedef pair<char,char> pii;
typedef vector<pii> vp1;
typedef vector<vp1> vp2;
typedef vector<vp2> vp3;
typedef vector<vp3> vp4;
typedef vector<vp4> vp5;
typedef vector<char> vc;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int R,C,M;
    cin >> R >> C >> M;
    vp4 before(R,vp3(C,vp2(R,vp1(C,mp(-1,-1)))));

    vector<vc> is_room(R,vc(C));
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            char t;cin >> t;
            is_room[r][c] = (t == '.');
        }
    }

    for(int s_r=0;s_r<R;s_r++){
        for(int s_c=0;s_c<C;s_c++){
            stack<pii> S;
            before[s_r][s_c][s_r][s_c] = mp(s_r,s_c);
            S.push(mp(s_r,s_c));
            while(not S.empty()){
                pii p = S.top();
                int r = p.first,c = p.second;
                S.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dy[i],nc = c + dx[i];
                    if(0 <= nr and nr < R and 0 <= nc and nc < C and
                       is_room[nr][nc] and before[s_r][s_c][nr][nc].first == -1){
                        before[s_r][s_c][nr][nc] = mp(r,c);
                        S.push(mp(nr,nc));
                    }
                }
            }
        }
    }

    vector<vector<int> > consume(R,vector<int>(C));
    vector<vector<int> > turn_on(R,vector<int>(C));
    vector<vector<int> > turn_off(R,vector<int>(C));

    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            cin >> consume[r][c];
        }
    }
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            cin >> turn_on[r][c];
        }
    }
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            cin >> turn_off[r][c];
        }
    }

    vector<vector<int> > last_visit(R,vector<int>(C,-1));
    int lr=-1,lc=-1;
    int cur_time = 0;
    int ret = 0;
    for(int t_case=0;t_case<M;t_case++){
        int gr,gc;
        cin >> gr >> gc;
        if(t_case == 0){
            lr = gr;lc = gc;
        }
        vp1 rou;
        pii cur = mp(gr,gc);
        while(not(cur.first == lr and cur.second == lc)){
            rou.push_back(cur);
            cur = before[lr][lc][cur.first][cur.second];
        }
        rou.push_back(mp(lr,lc));
        reverse(all(rou));

        for(size_t i=0;i<rou.size();i++){
            if(i != 0) cur_time++;
            int c_r = rou[i].first,c_c = rou[i].second;

            if(last_visit[c_r][c_c] != -1){
                ret += min(consume[c_r][c_c] * (cur_time - last_visit[c_r][c_c]),
                           turn_off[c_r][c_c] + turn_on[c_r][c_c]);
            }else{
                ret += turn_on[c_r][c_c];
            }
            last_visit[c_r][c_c] = cur_time;
            // cerr << c_r << " " << c_c << " " << cur_time << " " << ret << endl;
        }
        lr = gr,lc = gc;
    }
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(last_visit[r][c] != -1) {
                ret += turn_off[r][c];
            }
        }
    }
    cout << ret << endl;
    return 0;
}