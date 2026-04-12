#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define ll long long
#define pq priority_queue
#define mii map<int,int>
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<vi> vii;
typedef vector<ii> vpi;
typedef vector<ll> vll;
int oo = (1e9) + 7;
 
string s;
int d;
int tb[10005][105][2];
vi num;
 
int dp(int i, int n, int f) {
    if(i == (int)s.size() and n == 0) return 1;
    if(i == (int)s.size()) return 0;
    if(tb[i][n][f] != -1) return tb[i][n][f];
 
    int limit = f == 0 ? num[i] : 9;
    // Se o número formado já é menor que a entrada, podemos colocar qualquer dígito.
 
    int ans = 0;
    for(int dgt = 0; dgt <= limit; dgt++)
    {
        if(f == 0 and dgt < limit) ans = ans%oo + dp(i+1, (n%d+dgt%d)%d, 1)%oo;
        else if(f == 0 and dgt == limit) ans = ans%oo + dp(i+1, (n%d+dgt%d)%d, 0)%oo;
        if(f == 1) ans = ans%oo + dp(i+1, (n%d+dgt%d)%d, f)%oo;  
    }
    tb[i][n][f] = ans % oo;
    return ans % oo;
}
 
int main() {
    cin >> s >> d;
 
   
    for(size_t i = 0; i < s.size(); i++)
    {
        num.push_back(s[i] - '0');
    }
   
    memset(tb, -1, sizeof tb);
    printf("%d\n", (dp(0, 0, 0)+oo-1) % oo);
 
    return 0;
}
