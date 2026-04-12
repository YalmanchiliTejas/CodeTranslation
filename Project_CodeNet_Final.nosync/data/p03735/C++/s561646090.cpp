#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> xb(n), yb(n);
    vector<pair<long long int, long long int>> ball;
    long long int amax = 0, amin = 1e9 + 1;
    
    for(int i=0; i<n; i++){
        long long int x, y;
        cin >> x >> y;
        if(x < y) swap(x,y);
        xb[i] = x;
        yb[i] = y;

        amax = max(amax, x);
        amin = min(amin, y);
    }

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    multiset<long long int> blue;
    vector<long long int> draw_max, draw_min;
    for(int i=0; i<n; i++){
        if(xb[i] == amax){ draw_min.push_back(yb[i]); blue.insert(yb[i]); continue; }
        if(yb[i] == amin){ draw_max.push_back(xb[i]); blue.insert(xb[i]); continue; }

        ball.push_back({yb[i], xb[i]}); blue.insert(yb[i]);
    }
    bool flag = false;
    if(draw_min.size() == 1 && draw_min[0] == amax) flag = true;

    sort(xb.begin(),xb.end());
    sort(yb.begin(),yb.end());

    // case(1) amax = Rmax, amin = Bmin
    long long int ans = (xb[n-1]-xb[0]) * (yb[n-1]-yb[0]);

    // case(2) amax = Rmax, amin = Rmin (and Bmax != amax, Bmin != Bmin)
    if(flag == false){
        sort(ball.begin(), ball.end());

        long long int bmax = *prev(blue.end());
        long long int bmin = *blue.begin();
        long long int diff = bmax - bmin;

        for(auto b : ball){
            blue.erase(blue.find(b.first));
            blue.insert(b.second);

            bmax = *prev(blue.end());
            bmin = *blue.begin();
            diff = min(diff, bmax - bmin);
        }
        ans = min(ans, (amax - amin) * diff);
    }

    cout << ans << endl;
    return 0;
}