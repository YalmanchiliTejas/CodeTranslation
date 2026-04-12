#include <bits/stdc++.h>
#define fr(i, n, m) for(int i = (n); i < (m); i ++)
#define pb push_back
#define pq priority_queue
#define st first
#define nd second

using namespace std;
typedef long long ll;
ll const inf = 1e9;
ll const mod = 998244353;

ll p[51];
ll b[51];

string burger(int level){
    if(level == 0) return "P";
    else{
        return "B" + burger(level - 1) + "P" + burger(level - 1) + "B";
    }

}
ll f(ll level, ll k){
    if(k == 0) return 0;
    if(k == 1){
        if(level == 0) return 1;
        else return 0;
    }
    else if(k == b[level] + p[level]){
        return p[level];
    }
    else{
        ll mid = p[level - 1] + b[level - 1] + 2;
        if(k >= mid){
            return p[level - 1] + 1 + f(level - 1, k - mid);
        }
        else{
            return f(level - 1, k - 1);

        }

    }
}

int main()
{
    p[0] = 1;
    b[0] = 0;
    fr(i, 1, 51){
        p[i] = p[i - 1] * 2 + 1;
        b[i] = b[i - 1] * 2 + 2;
    }
    ll n, k;
    cin >> n >> k;
    cout << f(n, k) << endl;
    return 0;

}
