//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MOD = 1000000007;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//main code

int main(int argc, char const* argv[])
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> mass(h,vector<char>(w));
    for (int i = 0; i < h; i++) {
        bool erase = true;
        for (int j = 0; j < w; j++) {
            cin >> mass[i][j];
            if (mass[i][j] == '#') {
                erase = false;
            }
        }
        if (erase == true) {
            mass.erase(mass.begin() + i);
            h--;
            i--;
        }
    }

    for (int i = 0; i < w; i++) {
        bool erase = true;
        for (int j = 0; j < h; j++) {
            if (mass[j][i] == '#') {
                erase = false;
            }
        }
        if (erase) {
            for (int j = 0; j < h; j++) {
                mass[j].erase(mass[j].begin() + i);
            }
            i--;
            w--;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << mass[i][j];
        }
        cout << endl;
    }
    return 0;
}
