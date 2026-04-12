#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 移動方向

int n;
vector<string> s;

void input(){
    cin >> n;
    s.resize(n);
    for(int i=0;i<n;i++) cin >> s[i];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    string az = "abcdefghijklmnopqrstuvwxyz";
    int cnt[26];
    for(int i=0;i<26;i++){
        int rec = INF;
        int tmp;
        for(int j=0;j<n;j++){
            tmp = count(s[j].begin(), s[j].end(), az[i]);
            rec = min(rec, tmp);
        }
        cnt[i] = rec;
    }
    
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt[i];j++){
            cout << az[i];
        }
    }
    cout << endl;
    return 0;
}