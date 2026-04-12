///Coder ---->>>> Kael (Joan Marcos Rivera)
///Team ACM : CyberSpace ____ IPVCE FEDERICO ENGELS
///KingOfString
///Copyright

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

typedef long long ll;
typedef pair < int , int > par;

#define pb push_back
#define mp make_pair
#define s second
#define f first
#define maxn 3010
#define mod 1000000007
#define less(n) order_of_key(n)
#define en_pos(n) find_by_order(n) /// --- >> iterador --- >> empieza en 0

ll dp[maxn][maxn],a[maxn],t[maxn];
ll suma(int a,int b){
    return (t[b]-t[a-1]);
}
main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;cin >> n;

    for(int i=1;i<=n;i++)
        cin >> a[i] , dp[i][i] = a[i]  , t[i] = t[i-1] + a[i];

    for(int p=2;p<=n;p++){
        for(int i=1;i<=n;i++){
            int j = i + p - 1;
            if(j > n)break;
            dp[i][j] = max(suma(i,j-1) + a[j] - dp[i][j-1] , suma(i+1,j) + a[i] - dp[i+1][j]);
        }
    }

    cout << (2*dp[1][n])-suma(1,n);
}
/*
5 5
5 1
5 4
4 3
5 2
3 2
10
3 4
2 2
5 4
5 3
3 5
5 1
5 3
3 4
2 3
3 4*/
