        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
           int n,k;
           string s;
           cin>>n>>s>>k;
           for(int i=0;i<n;i++)if(s[i]!=s[k-1])s[i]='*';
           cout<<s;
           return 0;

        }
