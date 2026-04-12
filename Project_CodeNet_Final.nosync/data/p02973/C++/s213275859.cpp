#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <functional>
#include <deque>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int n;
    cin >> n;
    multiset<int> st;

    int a1;
    cin >> a1;
    st.insert(a1);
    for(int i = 1;i < n;i++){
        int a;
        cin >> a;
        auto p = st.lower_bound(a);

        if(p == st.begin())st.insert(a);
        else{
            p--;
            st.erase(p);
            st.insert(a);
        }
    }

    cout << st.size() << endl;
}
