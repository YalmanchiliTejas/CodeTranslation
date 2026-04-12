// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    multiset<int>st;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        if(st.size()==0)st.insert(-in);
        else{
            auto it = st.upper_bound(-in);
            if(it==st.end()){
                st.insert(-in);
            }
            else{
                st.erase(it);
                st.insert(-in);
            }
        }
    }
    cout << st.size() << endl;

    return 0;
}
