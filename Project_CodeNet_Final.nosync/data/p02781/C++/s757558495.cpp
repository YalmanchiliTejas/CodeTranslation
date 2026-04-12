#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef Lollipop
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

int sz;
vector<int> input;
ll dp[2][2][105][105];
string num;
int k;

ll cal(int is_start, int is_small, int pos, int value)
{
    if (pos >= sz){
        if (value == k){
            return 1;
        }
        return 0;
    }
    ll &ret = dp[is_start][is_small][pos][value];
    if (ret != -1){
        return ret;
    }
    ret = 0;
    int limit = is_small ? 9 : input[pos];
    if (is_start){
        for (int i = 1; i <= limit; i++){
            if (value + (i != 0) <= k){
                ret += cal(0, is_small | (i < input[pos]), pos + 1, value + (i != 0));
            }
        }
        ret += cal(1, 1, pos + 1, 0);
    }
    else{
        for (int i = 0; i <= limit; i++){
            if (value + (i != 0) <= k){
                ret += cal(0, is_small | (i < input[pos]), pos + 1, value + (i != 0));
            }
        }
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> num;
    cin >> k;
    sz = num.size();
    for (auto x : num){
        input.pb(x - '0');
    }
    mem(dp, -1);
    cout << cal(1, 0, 0, 0) << endl;
    return 0;
}


