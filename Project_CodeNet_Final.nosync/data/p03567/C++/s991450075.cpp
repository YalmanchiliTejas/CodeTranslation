#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=1;i<n;i++){
        if(s.substr(i-1,2)=="AC"){
            cout <<"Yes"<<endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}
