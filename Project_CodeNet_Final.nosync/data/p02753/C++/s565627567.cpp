#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define deb(x) cout << #x << " " << x << endl;

typedef long long ll;
const ll mod = 1000000007;

#define ffor(i,n) for(i=0;i<n;++i)

int main(){
    
 //   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t,i,n,j,m;


    string s;
    cin>>s;
    if(s[0]!='A'&&s[1]!='A'&&s[2]!='A')
        cout<<"No";
    else if(s[0]!='B'&&s[1]!='B'&&s[2]!='B')
        cout<<"No";
    else
    {
            cout<<"Yes";
    }
    


    

    cerr << "\n\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}