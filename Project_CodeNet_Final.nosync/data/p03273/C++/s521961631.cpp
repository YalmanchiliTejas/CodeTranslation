#include<bits/stdc++.h>
#define INF 1000000009
#define INFL 1000000000000000018
#define mod 10007
#define pb push_back
#define MAXN 505
#define ff first
#define sf second.first
#define ss second.second
using namespace std;
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef vector<int> VE;
typedef map<int, int> MAP;
char fid[200][200];
int h, w, cnt;
bool  a[200], b[200], flag;
signed main()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> fid[i][j];
            if(fid[i][j] == '.'){
                cnt++;
            }
        }
        if(cnt == w){
            a[i] = true;
        }
        cnt = 0;
    }
    cnt = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(fid[j][i] == '.'){
                cnt++;
            }
        }
        if(cnt == h){
            b[i] = true;
        }
        cnt = 0;
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!a[i] && !b[j]){
                cout << fid[i][j];
                flag = true;
            }
        }
        if(flag)cout << endl;
        flag = false;
    }

    return 0;
}

