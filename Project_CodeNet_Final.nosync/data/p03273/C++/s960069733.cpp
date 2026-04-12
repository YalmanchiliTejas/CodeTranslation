#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <cmath>
 
using namespace std;
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF (ll)1e18
#define MOD (ll)1e9 + 7
#define pb push_back
 
void no(){cout<<"No"<<endl;exit(0);}
void yes(){cout<<"Yes"<<endl;exit(0);}
void No(){cout<<"NO"<<endl;exit(0);}
void Yes(){cout<<"YES"<<endl;exit(0);}
 
typedef long long ll;
typedef long long int llt;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main(void)
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    string board[112];
    bool x[112]={0}, y[112]={0};
    for (int i = 0; i < h;i++){
        cin >> board[i];
    }
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++){
            if(board[i][j]=='#')
                x[i] = true, y[j] = true;
        }
    }
    for (int i = 0; i < h;i++){
        if(x[i]){
            for (int j = 0; j < w;j++){
                if(y[j])
                    cout << board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}