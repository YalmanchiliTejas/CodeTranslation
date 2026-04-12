#include <bits/stdc++.h>

using namespace std;

#define int long long
#define tie() ios_base :: sync_with_stdio(0); cin.tie(0) ; cout.tie(0)
#define err(x) cerr << #x << " is : " << x << endl
#define mem(a , v)   memset(a , v , sizeof a)
#define all(v) v.begin() , v.end()

const int N = 1e5 + 20;
const int mod = 1e9 + 7;

int32_t main()
{
      tie();
      int t = 1;
      //cin >> t;
      while(t--)
      {
            string s;
            cin >> s;
            set <char> st;
            for(char &x : s)
                  st.insert(x);
            if(st.size() == 2)
                  cout << "Yes" << endl;
            else
                  cout << "No" << endl;
      }
      return 0;
}
