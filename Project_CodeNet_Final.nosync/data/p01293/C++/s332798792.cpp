
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int check(string c){
    char a[20] = {"23456789TJQKA"};
    int i;
    rep(i,14)if(a[i] == c[0])break;
    return i;
}

int main(void) {
    int i,j;
    string s;
    while(cin >> s, s != "#"){
        char card[4][13][5];
        rep(i,4)rep(j,13) cin >> card[i][j];
        int win[2] = {};
        int leader = 0;
        rep(i,13){
            int t = 0, ts = 0;//2:切り札,1:リーダー,0:その他
            rep(j,4){
                if(card[j][i][1] == s[0]){
                    if(ts != 2) t = j, ts = 2;
                    else if(check(card[j][i]) > check(card[t][i])) t = j, ts = 2;
                }else if(card[j][i][1] == card[leader][i][1]){
                    if(ts == 1 && check(card[j][i]) > check(card[t][i]))t = j, ts = 1;
                    if(ts == 0) t = j, ts = 1;
                }else{
                    if(ts == 0 && check(card[j][i]) > check(card[t][i]))t = j, ts = 0;
                }
            }
            win[t%2]++;
            leader = t;
        }
        if(win[0] < win[1]){
            cout << "EW " << win[1] - 6 << endl;
        }else{
            cout << "NS " << win[0] - 6 << endl;
        }
    }
}

