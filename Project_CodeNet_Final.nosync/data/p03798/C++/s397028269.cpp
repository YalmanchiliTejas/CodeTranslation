#include <bits/stdc++.h>
#define rep(n) for (int I = 0; (I) < (n); ++(I) )
#define repeat(i, n) for( int i = 0; (i) < (n); ++(i) )
#define repeat_to(i, n) for( int i = 0; (i) <= (n); ++(i) )
#define repeat_from(i, m, n) for( int i = (m); (i) < (n); ++(i) )
#define repeat_from_to(i, m, n) for( int i = (m); (i) <= (n); ++(i) )
#define dump(x) cout << " " << #x << "=" << x
#define vdump(v) for(size_t T=0; T<v.size(); ++T){cout << " " << #v << "[" << T << "]=" << v[T];} cout << endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int n;
    string str;
    cin >> n >> str;
    
    auto makeseq = [](const string& str, vector<int> res) -> vector<int> {
        int n = str.size();
        assert(res.size() == 2);
        const int SHEEP = 1;
        const int WOLF  = -1;
        repeat_from_to(i, 1, n-2) {
            if ((str[i] == 'o' && res[i] == SHEEP) || (str[i] == 'x' && res[i] == WOLF))
                res.push_back( res[i-1] );
            else
                res.push_back( -res[i-1] );
        }
        return res;
    };
    
    auto isvalid = [](int mid, char say, int prev, int next) -> bool {
        const int SHEEP = 1;
        const int WOLF  = -1;
        bool res;
        if ((mid == SHEEP && say == 'o') || (mid == WOLF && say == 'x')) {
            res = (prev == next);
        }
        else {
            res = (prev != next);
        }
        return res;
    };
    
    auto show = [](vector<int> res) -> void {
        int n = res.size();
        repeat(i, n) {
            if (res[i] == 1) cout << 'S';
            else cout << 'W';
        }
    };
    
    vector<vector<int>> ss {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    repeat(i, 4) {
        vector<int> res = makeseq(str, ss[i]);
        if (isvalid(res[0], str[0], res[1], res[n-1]) && isvalid(res[n-1], str[n-1], res[n-2], res[0])) {
            show(res);
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}