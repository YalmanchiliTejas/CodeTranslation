#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
    int n;
    cin >> n;
    long a[n];
    rep(i,n){
        cin >> a[i];
    }
    multiset<long> st;
    int ans = 1;
    st.insert(a[0]);
    st.insert(1e9+7);
    for(int i = 1;i<n;i++){
        if(a[i]>*st.begin()){
            auto itr = st.lower_bound(a[i]);
            itr--;
            st.erase(itr);
            st.insert(a[i]);
        }
        else{
            st.insert(a[i]);
        }
    }
    cout << st.size()-1 << endl;
}