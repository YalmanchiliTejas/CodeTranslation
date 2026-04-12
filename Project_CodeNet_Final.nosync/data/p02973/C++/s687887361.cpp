#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
multiset < int > st;
int ans;

int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);

        auto it = st.lower_bound(x);
        if(it == st.begin()){
            ans++;
            st.insert(x);
            continue;
        }

        it--;
        st.erase(it);
        st.insert(x);
    }

    cout << ans << endl;

    return 0;
}
