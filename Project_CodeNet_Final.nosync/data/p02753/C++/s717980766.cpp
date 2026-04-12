#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define ppb pop_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int N = 1e5 + 667;
char a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<3;i++){
        cin >> a[i];
    }
    sort(a, a+3);
    if(a[0] == a[2]){
        cout << "No";
    }
    else cout << "Yes";
    return 0;
}
