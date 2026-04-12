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

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair

#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)

const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

int main(){
    int n;
    while(cin >> n, n){
        int field[n][n];
        for(int i=0; i < n; i++)for(int j=0; j< n; j++) field[i][j] = 0;
        int x = n/2+1, y = n/2;
        field[x][y] = 1;
        for(int i=2; i <= n*n; i++){
            x++; y++;
            if(!(0 <= x && x < n)) x = 0;
            if(!(0 <= y && y < n)) y = 0;
            if(field[x][y] != 0){
                x++; y--;
                if(!(0 <= x && x < n)) x = 0;
                if(!(0 <= y && y < n)) y = n-1;
            }
            field[x][y] = i;
        }
        for(int i=0; i< n; i++){
            for(int j=0; j < n; j++){
                printf("% 4d", field[i][j]);
            }
            cout << endl;
        }
    }
}