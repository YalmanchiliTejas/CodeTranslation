
/*
    Author: Shivam Shukla
    Title : DP_L.cpp
    Date : 01/09/2020   >> 13:17:35

    AtCoder Problem L: Deque

    This problem asks to find the outcome of the game, not the winner but the outcome that what will
    be the final value of X - Y, where X and Y are the points earned by two players erespectively.
    Provided that the choices made by the players are optimal and are not biased in any of the cases.

    Since here an important point is made, that players always choose the optimal choice and never the 
    arbitrary or game biased choices in any way, this ensures that provided a series of numbers there
    will always be only a single outcome and that outcome will be optimal as much as possible for the 
    game as well. 

    In order for the things to go well and better moves, there can be no way that player chooses an 
    optimal move i real life, but here we can say that when the outcome is known there is always existancew
    of the optimal move as well because we actually try to reach to that outcome in order to get the 
    things done. 

    So from the start of the given series or the given numbers we have to explore the given choices 
    in order to get the values that can be optimal. So actually how to do this - but here is an important 
    point, every even chance (srtarting from 0) will be considered positive and every odd chance (starting from 1)
    will be considered negative since they bleong to the player 1 and 2 respectively.

    The choices made by the players can be only from the edges and never from the in between. 

    Consider a solve type of function which would take the series into the consideration and that series 
    would be used to find the optimal answeer and that answer will be fixed, our solve function through the
    use of different choices will ensure that optimal values can be found. In order to find the optimal values
    it is important to note that there is always a presence of the factor like who will be choosing what.

    So if the current level is even then for sure the value will be choosen will be positive and rest of the
    resursion values will be considered negative while if the current level is negative then the other 
    values will be considered positive then.
    Now think about this way,

    solve(series, i, j) {
        if (i == j)
            return series[i];
        return max(series[i] - solve(series, i + 1, j), series[j] - solve(i, j - 1));    
    }

    solve(series, 0, n - 1);

    The approach seems quite promising, lets talk of something like dry run over it in the terms of, 
    following series of numbers, (80, 90, 30) - the best outcome that can be obtained here is : 80 - 90 + 30 = 20

    So solve(80, 90, 30) = max(80 - solve(90, 30), 30 - solve(80, 90))
       => 80 - 90 + solve(30), 80 - 30 + solve(90), 30 - 80 + solve(90), 30 - 90 + solve(80)
       => 20, 140, 40, 20

    So as in the given case of our solution, it takes an interval and finds out whether or not we can use this
    ineterval for finding the largest value, upon getting the largest value from the any of the given intervals
    we would take the consideration of one of them. 

    max(a[i] - solve(a, i + 1, j), a[j] - solve(a, i, j - 1))

    When we would get the maximum value for the interval then for sure our task would be completyed here
    the supposition in the given condition is that 

    a[i] - solve(a, i + 1, j)

    This signifies that each player plays with the mentality that its contributin will be negated
    by other. Here also it can also be supposed that we would try to remove that value and leave the 
    rest to the other player. Now other player plays with the optimal chances of his own and not 
    from the optimality of the player1. 

    Time Complexity : O(2 ** n)
    Space Complexity : O(2 ** n) (Recursion Space taken)

    In order to find the optimal solution this conplexity is way too much, now in order to optimize it
     we need some clues or some patterns in the problem, one clue is eveident from the recrsion posed above

     In the recursion we can see that the answer for the interval (i, j) is dependent upon the smaller 
     subproblems, (i + 1, j) and (i, j - 1). This shows the very important property known as Optimal Substructure

     Optimal Substructure ensures that the bigger problems can bw solved using the optimal answer to the smaller
     subprpoblems. The smaller subproblems can be solved by further division among them. 

     But yet the time compleexity remains same since we haven't improved anything in the code itself letys watch 
     over a recuriosn state, solve(a, 0, 3) 

     solve(0, 3) = solve(1, 3), solve(0, 2) = solve(1, 2), solve(2, 3), solve(1, 2), solve(0, 1)

    This is a pretty smaller recursion and we can see that solve(1, 2); occured at least 2 times. 
    In these given times, we can think of when there is a pretty much larger problem to solve anmd when
    this happens there is a waste of both time and space complexity in the given algortihm.

    This shows a very important property here, overlapping subproblems, the overlapping subproblems if removed
    can ensure a better runtime complexity and therefore we have use a programming paradigm.

    Dynamic Programming is such paradigm of programming which uses these 2 hallmarks or the problem
    for solving them out, 

    1. Optimal Substructure
    2. Overlapping Subproblems

    These both thehallmarks provide the intuition for using DP into this problem. Since matters come 
    to DP, therefore we need to figure out the states. The states need to be figured out for finding the
    optimal subproblems and transition provides the way to use optimal substructures.

    vl a(n);
    vc(vl) dp(n, vl(n));

    solve(i, j) {
        repa(i, n) 
            dp[i][i] = a[i];
        repa(i, n)
            repa(j, i + 1)
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);

        return dp[n - 1][n - 1];            
    } 

    Time Complexity : O(n * n) (Precisely : O(n * (n - 1) / 2))
    Space Complexity : O(n * n) 

    This is a better form of complexity and would yeild a better runtime complexity at least from the 
    point of acceptance of this problem.
*/

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pair<ll,ll> > vpll;
 
const int MOD=1e9+7;
const int MAX=1e5+5;
const double PI= acos(-1.0);
const long double EPS=1e-10;
const int64_t INF=1e18+10;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define trace(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vi vector<int>
#define vl vector<ll>
#define vs vector<str>
#define vc(x) vector<x>
#define mapll map<ll,ll>
#define mapib map<int,bool>
#define mapiv map<int,vector>
#define mapsi map<string,int>
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define down(i,j,k) for(ll i=j;i>=k;i--)
#define repa(i,n) for(ll i=0;i<n;i++)
#define dowa(i,n) for(ll i=n;i>=0;i--)
#define reps(i,j,k,s) for(ll i=j;i<k;i+=s)
#define downs(i,j,k,s) for(ll i=j;i>=k;i-=s)
#define trv(i,x) for(auto i:x)
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define str string 
#define dub double
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vl,greater<ll> >
#define INF(x) numeric_limits<x>::max()
 
template<typename t> t lcm(t a, t b) {return (a*b)/__gcd(a,b);}
template<typename t> t gcd(t a, t b) {return __gcd(a,b);}
template<typename t> t mul_mod(t a, t b, t m){t res=((a%m)*(b%m)%m); return res;}
template<typename t> t add_mod(t a, t b, t m){t res=((a%m)+(b%m))%m; return res;}
template<typename t> t pow_mod(t a,t b,t m) {t res=1;while(b){if(b&1) res=mul_mod(res,a,m);a=mul_mod(a,a,m), b>>=1;} return res%m;}
template<typename t> vc(t) num_vec(t num) {t res; while (num) res.pb(num%10), num/=10; return res;}
template<typename t> t vec_num(t vec) {t res=0; ll mul=1; repa(i,sz(vec)) res=vec[i]*mul, mul*=10; return res;}

unordered_map<int, unordered_map<int, ll>> dp;

ll solve(vl& a, int i, int j) {
    if (i > j) 
        return 0;
    if (i == j) 
        return a[i];
    if (dp.count(i) && dp[i].count(j))    
        return dp[i][j];
        
    dp[i][j] = max(a[i] - solve(a, i + 1, j), a[j] - solve(a, i, j - 1));
    return dp[i][j];
} 

int32_t main(int argc,char** argv){
    fastio();
    auto tstart= clock();
 
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt","w",stderr);
    #endif   

    int n; cin >> n;
    vl a(n); repa(i, n) cin >> a[i];

    cout << solve(a, 0, n - 1);

    cerr << setprecision(2) << fixed<<"Time elapsed: " << (double)(clock() - tstart)/CLOCKS_PER_SEC << endl; 
    return 0; 
}