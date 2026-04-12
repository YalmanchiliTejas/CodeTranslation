/// إِنَّ مَعَ الْعُسْرِ يُسْرًا
/// لَا أَبْرَحُ حَتَّىٰ أَبْلُغَ

#include <bits/stdc++.h>
#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define LL long long
#define ll long long
#define LD double

#define HabdModeActive ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define PI acos(-1)
#define MAX 5000005
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);


int main() {
    HabdModeActive
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n; i++)
        cin>>arr[i];
    reverse(arr,arr+ n );
    vector<int> se;
    for(int i = 0 ; i<n ; i++)
    {
        auto it = upper_bound(se.begin() , se.end() , arr[i]);
        if(it != se.end()) *it = arr[i];
        else se.push_back(arr[i]);
    }
    cout<<se.size();
    return 0;
}