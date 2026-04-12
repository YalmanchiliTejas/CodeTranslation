/*
                     .:*+=%@@@@@@=-.
                 .:=@#@@@#@@#######%==*.
              .-=####@######%*-.....:%##%.
            .*@###########%+:--........-%@-
          .*@##############@+--.........-:%-
        .+##################@==%%%%=+*:----+.
      .-@####################%++%@@@@@=+**%@@*
      .%###################@%%@@@###@%+:--%@@%.
     -@###################@%%%%*::*%++:-----=@+.
    -#####################@%=++++++*:-------.-=:
   .+####################@%++*::-:::--::*:::***=:
   .@#####################%=++*::::-:::++*=##@@#@-
  ..#####################@%%=++**:::::**+%@#@%%##-..
   .%####################@@%=+++*+****::*=@######@.
  .=######################@%%==+==++**+=@%@##@###+:...
  -#######################@@@%%%===++=@@@%=++===*::--...
  -########################@@@@@@@%==%%=++==@@:::::*:--.
..:#########################@@@@@@%%======++++::-..:-.--...
%#############################@###@%%@@%==%=%*----.--.::---.
#############################################*-:*:-:---*---- .
#############################################*--*--:---*---:-.
#############################################+--::--::-*::-::.
###########################################+:*-.---.---.:---*-..
###########################################**:-----------------.
##########################################@::**:--::::::--:::::-
###########################################:--:*:::::::::**::*+*
###########################################=:::***::::::**:::*+*
############################@@@@@@#########@+****::::********+++
############################@%%%%%@@@@@@@###%+***::::::::***+==+
############################@%%%%%%%%%%%@####=+:::-::::-::*+=%%+
#############################@%%%%%%%%%%@#####=::--------:*=%@%+
%###########################@%%%%==%%%%%%@##@#=:------..-:+%@@%=
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/
#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

int mysqrt(ll x){
    int l = 0, r = 1e9 + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (m * (ll)m <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

mt19937 rnd(1337);

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

const int Mod = 1e9 + 7;

int bpow(int x, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % Mod;
    if (y & 1)
        ret = (ret * (ll)x) % Mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, Mod - 2)) % Mod;
}

void setmin(int &x, int y){
    x = min(x, y);
}

void setmax(int &x, int y){
    x = max(x, y);
}

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

const ll llinf = 2e18 + 100;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int o(int x){
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
    return x;
}

int f(ll x){
    return x % mod;
}

int n, m, start, finish;

vector<pair<int, int> > e[maxn];

ll d[maxn];

set<pair<ll, int> > g;

bool good[maxn];

int dp[2][maxn];

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("sprinklers.in");
    //ofstream cout("sprinklers.out");
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> start >> finish;
    start--;
    finish--;
    for (int i = 0; i < m; i++){
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        e[v].push_back(make_pair(u, w));
        e[u].push_back(make_pair(v, w));
    }
    for (int i = 0; i < n; i++)
        d[i] = llinf;
    d[start] = 0;
    g.insert(make_pair(0, start));
    while (!g.empty()){
        int v = g.begin()->second;
        g.erase(g.begin());
        for (auto ut : e[v]){
            int u = ut.first, w = ut.second;
            if (d[u] > d[v] + w){
                g.erase(make_pair(d[u], u));
                d[u] = d[v] + w;
                g.insert(make_pair(d[u], u));
            }
        }
    }
    good[finish] = 1;
    g.insert(make_pair(finish, 0));
    while (!g.empty()){
        int v = g.begin()->first;
        g.erase(g.begin());
        for (auto ut : e[v]){
            int u = ut.first, w = ut.second;
            if (!good[u] && d[v] == d[u] + w){
                good[u] = 1;
                g.insert(make_pair(u, 0));
            }
        }
    }
    vector<int> order;
    vector<pair<ll, int> > srt;
    for (int i = 0; i < n; i++)
    if (good[i])
        srt.push_back(make_pair(d[i], i));
    n = srt.size();
    sort(srt.begin(), srt.end());
    order.resize(n);
    for (int i = 0; i < n; i++)
        order[i] = srt[i].second;
    dp[0][start] = 1;
    for (auto v : order){
        for (auto ut : e[v]){
            int u = ut.first, w = ut.second;
            if (good[u] && d[u] == d[v] + w)
                dp[0][u] = o(dp[0][u] + dp[0][v]);
        }
    }
    reverse(order.begin(), order.end());
    dp[1][finish] = 1;
    for (auto v : order){
        for (auto ut : e[v]){
            int u = ut.first, w = ut.second;
            if (good[u] && d[u] == d[v] - w)
                dp[1][u] = o(dp[1][u] + dp[1][v]);
        }
    }
    int ans = f(dp[0][finish] * (ll)dp[0][finish]);
    for (auto v : order){
        if (d[finish] == d[v] * 2){
            ans = o(ans - f(f(dp[0][v] * (ll)dp[0][v]) * (ll)f(dp[1][v] * (ll)dp[1][v])));
            continue;
        }
        for (auto ut : e[v]){
            int u = ut.first, w = ut.second;
            if (good[u] && d[u] == d[v] + w && d[v] * 2 < d[finish] && d[u] * 2 > d[finish])
                ans = o(ans - f(f(dp[0][v] * (ll)dp[0][v]) * (ll)f(dp[1][u] * (ll)dp[1][u])));
        }
    }
    cout << ans;
}
