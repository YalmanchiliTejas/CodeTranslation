#include <bits/stdc++.h>
using namespace std;

#define pb            push_back
#define mp            make_pair
#define ins           insert
#define endl          '\n'
#define all(x)        x.begin(),x.end()
#define debug(X)      { cerr<<endl<<(#X)<<" = "<<(X)<<endl; }
//#define cerr if(0)cerr

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    
    if (s[0]==s[1] && s[1]==s[2])
        cout<<"No";
    else
        cout<<"Yes";

}
