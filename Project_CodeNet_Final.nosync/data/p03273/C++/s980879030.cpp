#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
template<class T> istream& operator >> (istream& s, vector<T>& v) {
  for (T& x: v) s >> x;
  return s;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    int H, W; cin >> H >> W;
    vector<string> v;;

    string s;
    rep(i, H) {
        cin >> s;
        if (s.find('#')!=string::npos)
            v.push_back(s);
    }

    vector<bool> col(W, false);
    rep(j, W) {
        rep(i, v.size()) {
            if (v[i][j] == '#') {
                col[j] = true;
                break;
            }
        }
    }

    rep(i, v.size()) {
        rep(j, W)
            if (col[j])
                cout << v[i][j];
        cout << endl;
    }
}
