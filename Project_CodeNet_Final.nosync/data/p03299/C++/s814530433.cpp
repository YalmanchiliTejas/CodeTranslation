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

///YEAH IM THE BEST I'VE EVER WAS

///SO HAPPY

#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

/*char memory[(int)1e8];

char memorypos;

inline void * operator new(size_t n){
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}

inline void operator delete(void *){}
*/

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef unsigned int uint;

ll sqr(ll x){
    return x * x;
}

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

mt19937 rnd(1227);

mt19937_64 rndll(12365);

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

const int Mod = 1e9 + 7;

int Bpow(int x, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = Bpow(x, y >> 1);
    ret = (ret * (ll)ret) % Mod;
    if (y & 1)
        ret = (ret * (ll)x) % Mod;
    return ret;
}

int Bdiv(int x, int y){
    return (x * (ll)Bpow(y, Mod - 2)) % Mod;
}

void setmin(int &x, int y){
    x = min(x, y);
}

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = min(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

const ll llinf = 2e18 + 100;

const double eps = 1e-9;

const int maxn = 1e5 + 10, maxw = 1e6 + 10, inf = 1e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int n;

int arr[100];

pair<int, int> srt[101];

map<int, int> mp;

int ord[101];

int q[101][100][100][2][2][2];

void add(int &x, int y){
    x += y;
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
}

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("gymnasts.in");
    //ofstream cout("gymnasts.out");
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i], srt[i] = make_pair(arr[i], i);
    sort(srt, srt + n, [&](pair<int, int> x, pair<int, int> y){
            return x.first > y.first || (x.first == y.first && x.second < y.second);
         });
    srt[n].first = 1;
    for (int i = 0; i <= n; i++)
    if (i == 0 || srt[i].first != srt[i - 1].first)
        mp[srt[i].first] = mp.size() - 1, ord[mp.size() - 1] = srt[i].first;
    for (int it = 0; it < n; it++){
        int i = srt[it].second;
        int l = i, r = i + 1;
        while (l >= 0 && arr[l] >= arr[i])
            l--;
        while (r < n && arr[r] > arr[i])
            r++;
        l++;
        r--;
        int t = mp[srt[it].first];
        if (l == r){
            q[t][l][r][0][0][0] = 1;
            q[t][l][r][1][1][0] = 1;
            continue;
        }
        int t1 = 0, t2 = 0;
        for (int j = i - 1; j >= l; j--)
            t1 = max(t1, mp[arr[j]]);
        for (int j = i + 1; j <= r; j++)
            t2 = max(t2, mp[arr[j]]);
        if (l < i && t1 < t){
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    q[t][l][i - 1][a][b][0] = ((q[t1][l][i - 1][a][b][0] + q[t1][l][i - 1][!a][!b][0]) * (ll)Bpow(2, ord[t1] - ord[t] - 1)) % mod,
                    q[t][l][i - 1][a][b][1] = q[t1][l][i - 1][a][b][1];
        }
        if (r > i && t2 < t){
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    q[t][i + 1][r][a][b][0] = ((q[t2][i + 1][r][a][b][0] + q[t2][i + 1][r][!a][!b][0]) * (ll)Bpow(2, ord[t2] - ord[t] - 1)) % mod,
                    q[t][i + 1][r][a][b][1] = q[t2][i + 1][r][a][b][1];
        }
        if (l == i){
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++){
                    q[t][l][r][a][b][0] = q[t][l + 1][r][!a][b][0];
                    for (int x = 0; x < 2; x++)
                        add(q[t][l][r][a][b][1], q[t][l + 1][r][x][b][1]);
                    add(q[t][l][r][a][b][1], q[t][l + 1][r][a][b][0]);
                }
            continue;
        }
        if (r == i){
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++){
                    q[t][l][r][a][b][0] = q[t][l][r - 1][a][!b][0];
                    for (int x = 0; x < 2; x++)
                        add(q[t][l][r][a][b][1], q[t][l][r - 1][a][x][1]);
                    add(q[t][l][r][a][b][1], q[t][l][r - 1][a][b][0]);
                }
            continue;
        }
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++){
                for (int c = 0; c < 2; c++)
                    add(q[t][l][r][a][b][0], (q[t][l][i - 1][a][!c][0] * (ll)q[t][i + 1][r][!c][b][0]) % mod);
                int w = 0, h = 0;
                for (int x = 0; x < 2; x++)
                    for (int o = 0; o < 2; o++)
                        add(w, q[t][l][i - 1][a][x][o]),
                        add(h, q[t][i + 1][r][x][b][o]);
                q[t][l][r][a][b][1] = (w * (ll)h * (ll)2) % mod;
                add(q[t][l][r][a][b][1], -q[t][l][r][a][b][0]);
            }
    }
    if (srt[n - 1].first != 1){
        int t = mp.size() - 1, t1 = t - 1;
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                q[t][0][n - 1][a][b][0] = ((q[t1][0][n - 1][a][b][0] + q[t1][0][n - 1][!a][!b][0]) * (ll)Bpow(2, ord[t1] - ord[t] - 1)) % mod,
                q[t][0][n - 1][a][b][1] = q[t1][0][n - 1][a][b][1];
    }
    int t = mp.size() - 1;
    int ans = 0;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int x = 0; x < 2; x++)
                add(ans, q[t][0][n - 1][a][b][x]);
    cout << ans;
}
