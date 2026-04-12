#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define all(x) (x).begin(),(x).end()
#define dlog(x) cerr<<#x<<'='<<x<<endl
#define f first
#define s second
#define endl '\n'
#define sq(x) (x)*(x)*1ll
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
//      tree_order_statistics_node_update> indexed_multiset;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//      tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef pair<int,int> pii;



int main () {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//        freopen("test_input.txt", "r", stdin);
        int a = 0, b= 0;
        string str; cin >> str;
        for (const auto w: str)
                a += w == 'A', b += w == 'B';

        if (a && b) cout << "Yes";
        else cout << "No";
        return 0;
}