#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

//container util
//------------------------------------------
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair

//repetition
//------------------------------------------
#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)

enum{U = 0, D = 1, N = 2, E = 3, W = 4, S = 5};
int dice[] = {1, 6, 5, 3, 4, 2};

void rotate(int a, int b, int c, int d){
    int t = dice[a];
    dice[a] = dice[b];
    dice[b]= dice[c];
    dice[c] = dice[d];
    dice[d] = t;
}

int main(){
    int n;
    while(cin >> n, n){
        int ans = 0;
        dice[0] = 1; dice[1] = 6; dice[2] = 5; dice[3] = 3; dice[4] = 4; dice[5] = 2;
        rep(i, n){
            string s;
            cin >> s;


            if(s[0] == 'N') rotate(U, S, D, N);
            else if(s[0] == 'E') rotate(E, U, W, D);
            else if(s[0] == 'W') rotate(U, E, D, W);
            else if(s[0] == 'S') rotate(U, N, D, S);
            else if(s[0] == 'R') rotate(S, E, N, W);
            else if(s[0] == 'L') rotate(S, W, N, E);

            ans += dice[U];
        }
        cout << ans+1 << endl;
    }
}