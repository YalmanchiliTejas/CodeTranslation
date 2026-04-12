#include <iostream>
#include <cstdio>
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
#include <cctype>
#include <complex>
#include <string>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define mp(a,b) make_pair((a),(b))
#define eq ==

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

// →↑←↓
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};


const double EPS = 1e-9;
//2,3,4,5,6,7,8,9,T(10),J(jack),Q(queen),K(king),A (ace)
//0,1,2,3,4,5,6,7,8,    9       10        11     12
int rank(char c){
    if(isdigit(c)) return c-'2';
    if(c == 'T') return 8;
    else if(c == 'J') return 9;
    else if(c == 'Q') return 10;
    else if(c == 'K') return 11;
    else if(c == 'A') return 12;
}

struct Tramp{
    char type;
    int ran;
    Tramp(char t,char r){
        type = t;
        ran = rank(r);
    }
    Tramp(){
    };
};

int main(){
    while(true){
        char tramp;
        cin >> tramp;
        if(tramp == '#') return 0;
        vector<vector<Tramp> > ts(4);

        for(int i=0;i<4;i++){
            for(int j=0;j<13;j++){
                char t,n;
                cin >> n >> t;
                ts[i].push_back(Tramp(t,n));
            }
        }

        int first = 0;
        vector<int> p(2);
        for(int i=0;i<13;i++){
            Tramp f = ts[first][i];
            int winner = first;
            for(int k=0;k<4;k++){
                if(k == first) continue;
                Tramp s = ts[k][i];
                if(f.type == tramp){
                    if(s.type == tramp and f.ran < s.ran){
                        f = s;
                        winner = k;
                    }
                }else if(s.type == tramp){
                    f = s;
                    winner = k;
                }else if(f.type == s.type and f.ran < s.ran){
                    f = s;
                    winner = k;
                }
            }
            p[winner%2]++;
            first = winner;
        }

        if(p[0] < p[1]) cout << "EW" << " " << p[1]-6 << endl;
        else cout << "NS" << " " << p[0]-6 << endl;
    }
    return 0;
}