
#include<bits/stdc++.h>
#define debug(x) cerr << "[" << #x <<": " << (x) <<"]"<< endl
#define pii pair<int,int>
#define clr(a,b) memset((a),b,sizeof(a))
#define rep(i,a,b) for(int i = a;i < b;i ++)
#define pb push_back
#define MP make_pair
#define LL long long
#define ull unsigned LL
#define ls i << 1
#define rs (i << 1) + 1
#define fi first
#define se second
#define ptch putchar
#define CLR(a) while(!(a).empty()) a.pop()

using namespace std;
inline LL read() {
    LL s = 0,w = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-')
            w = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
inline void write(LL x) {
    if(x < 0)
        putchar('-'), x = -x;
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
#ifndef ONLINE_JUDGE
clock_t prostart = clock();
#endif

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    string s; cin >> s;
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0;i < s.size();++ i)
        if(s[i] == 'A') ++ cnt1;
        else ++ cnt2;
    if(cnt1 && cnt2) cout << "Yes" << endl;
    else cout << "No" << endl;

#ifndef ONLINE_JUDGE
    cerr << "time: " << 1.0 * (clock() - prostart) / CLOCKS_PER_SEC << " s" << endl;
#endif
    return 0;
}
