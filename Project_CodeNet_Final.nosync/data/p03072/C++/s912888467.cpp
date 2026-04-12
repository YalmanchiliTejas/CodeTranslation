#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
using namespace std;
 
int main(){
    int n,c=0;
    cin>>n;
    vector<int> s(n);
    vector<int> l;
    rep(i,n) cin>>s[i];
    rep(i,n-1){
        l.push_back(s[i]);
        sort(ALL(l));
        if (l[i]<=s[i+1]) c++;
    }
    cout<<c+1<<endl;
    return 0;
}