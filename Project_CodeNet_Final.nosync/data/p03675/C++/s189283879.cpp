//In th name of ALLAH\\

// m    m  mmmm  mmmmm          mmmm   mmmm
// #    # m"  "m   #           "   "# m"  "m
// #mmmm# #    #   #             mmm" #    #
// #    # #    #   #     """       "# #    #
// #    #  #mm#  mm#mm         "mmm#"  #mm#

#include <bits/stdc++.h>
#define cn const int
#define ll long long
#define pq priority_queue
#define enter cout << endl
#define pb push_back
#define ff first
#define ss second
#define pii pair <int, int>
#define vi vector <int>
#define msi map <string, int>
#define Qi queue <int>
#define dQi deque <int>
#define str string
#define int ll
#define FOR(v, i, j) for (int v = i; v < j; v ++)
#define ROF(v, i, j) for (int v = i; v > j; v --)
using namespace std;

//START hh : mm \\// ET mm + mm
//	       END hh : mm

cn mod = 1e9 + 7;
cn inf = 2e9 + 9e2;
const ll linf = 2e18 + 18e2;
cn MAXN = 2e5 + 5e2;

int a[MAXN];

void f(int n) {
    if (n == 0) {cout << a[0] << ' '; return;}
    if (n < 0) return;
    cout << a[n] << ' ';
    f(n-2);
    cout << a[n-1] << ' ';
}

main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i =0 ;i < n;i ++)
        cin >> a[i];
    f(n - 1);
    return 0;
}

//Sea do not have any space for unmanned ships
//This region of city is safe, i have been tried to stay alive
//I used to be good till this city makes me bad with its drought

// m    m mmmmmm m      m      mmmmm         mmmmm     mm
// #    # #      #      #        #           #        m"#
// #mmmm# #mmmmm #      #        #           """"mm  #" #
// #    # #      #      #        #     """        # #mmm#m
// #    # #mmmmm #mmmmm #mmmmm mm#mm         "mmm#"     #
//	        	   H-54703802904130102
