#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;


void solved()
{   
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB")cout << "No";
    else cout <<"Yes";
}


int main()
{
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#endif 
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solved();
        cout <<"\n";
    }

#ifdef LOCAL
    system("pause");
#endif 
    return 0;
}