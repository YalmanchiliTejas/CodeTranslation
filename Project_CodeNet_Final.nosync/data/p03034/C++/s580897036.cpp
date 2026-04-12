#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n;
    cin >> n;
    vector<int> s;
    rep(i, n){ int tmp; cin >> tmp; s.push_back(tmp);}

    // c-1
    ll max_score = 0;
    for (int c = 1; c < n; c++)
    {
        ll score = 0;
        set<int> hasu;
        hasu.insert(0);
        hasu.insert(n-1);
        for(int x = 1; c * x < n; x++){
            if (c >= n-1-c*x) break;
            int cx = c*x;
            int ccx = n - 1 - cx; 
            score += s[cx];
            if (hasu.find(cx) != hasu.end()) break;
            hasu.insert(cx);
            score += s[ccx];
            if (hasu.find(ccx) != hasu.end()) break;
            hasu.insert(ccx);
            max_score = max(max_score, score);
        }

    }
    
    cout << max_score << endl;
}
