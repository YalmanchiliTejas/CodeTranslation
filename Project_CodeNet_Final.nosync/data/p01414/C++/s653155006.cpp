#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

void sbit(int &n, int i) {
    n |= (1<<i);
}

int cbit(int n, int i) {
    return n & (1<<i);
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int> > brush;
    vector<int> pats;
    for(int i = 0; i < N; ++i) {
        int h, w;
        cin >> h >> w;
        brush.push_back(make_pair(h, w));

        for(int bx = -4; bx <= 3; ++bx) {
            for(int by = -4; by <= 3; ++by) {
                int mask = 0;
                for(int x = 0; x < 4; ++x) {
                    for(int y = 0; y < 4; ++y) {
                        if(bx <= x && x < bx+w && by <= y && y < by+h) sbit(mask, y*4+x);
                    }
                }
                if(mask != 0) pats.push_back(mask);
            }
        }
    }

    vector<string> correct(4);
    for(int i = 0; i < 4; ++i) {
        cin >> correct[i];
    }

    int cmask[3] = {};
    {
        string cstr = "RGB";
        for(int i = 0; i < 3; ++i) {
            for(int y = 0; y < 4; ++y) {
                for(int x = 0; x < 4; ++x) {
                    if(correct[y][x] == cstr[i]) sbit(cmask[i], y*4+x);
                }
            }
        }
    }

    vector<int> memo(1<<16, INT_MAX);
    queue<pair<int, int> > q;

    int ans = 0;
    memo[0] = 0;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        int cost = q.front().first;
        int pat = q.front().second;
        q.pop();

        if(pat == 0xffff) {
            ans = cost;
            break;
        }

        //if(memo[pat] <= cost) continue;
        //memo[pat] = cost;

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < pats.size(); ++j) {
                int mask = pats[j] & cmask[i];
                int next = pat;
                next &= ~pats[j];
                next |= mask;
                if(memo[next] == INT_MAX) {
                    memo[next] = cost+1;
                    q.push(make_pair(cost+1, next));
                }
            }
        }
    }

    cout << ans << endl;
}