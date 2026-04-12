#include <bits/stdc++.h>
using namespace std;
#define endl              "\n"
#define pb              push_back
#define fir               first
#define sec               second
#define all(v)            ((v).begin()), ((v).end())
#define sz(v)            ((int)((v).size()))
#define ll              long long
#define ld              long double
#define lp(i, n)        for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)       for(int i=x ; (int)i<=n ; i++)
#define isPowerOfTwo(s) (!(s & (s-1)))
typedef vector<int> vi;
typedef deque<int> de;
void origi() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
void tiranga() {
    int n;
    cin >> n;
    multiset<int>mm;
    int x;
    cin >> x;
    mm.insert(x);
    lp(i, n - 1) {
        cin >> x;
        auto itr = mm.lower_bound(x);
        if (itr == mm.begin()) mm.insert(x);
        else mm.erase(--itr) , mm.insert(x);
    }
    cout << mm.size();
}
int main() {
#ifndef ONLINE_JUDGE.
    //freopen("input.txt", "r", stdin);
#else
#endif
    
    origi();
    tiranga();
    //cout << sumOfDig(123654);
   // genLarge(10, 10);
   // genSmall(10);

}
