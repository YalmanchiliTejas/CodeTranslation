#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
int main() {
    int n;cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    vector<int> st;
    int k = 1;
    st.push_back(-a[0]);
    for(int i = 1;i<n;i++){
        // for(auto l:st)
        //cerr <<  l << " ";
        auto s =upper_bound(st.begin(),st.end(), -a[i]);
        if(s==st.end()){
            st.push_back(-a[i]);
         //   cerr << a[i] << "NEW"<<endl;
        }else{
          //  cerr << a[i] << "idex"<<endl;
            *s= -a[i];
        }
        
    }
    cout << st.size() << endl;

}
