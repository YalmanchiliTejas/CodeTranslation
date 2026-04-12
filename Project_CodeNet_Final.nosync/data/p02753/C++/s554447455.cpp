#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define ll long long
#define pb push_back
#define f(i,k) for(int i = 0;i<k;i++)
using namespace std;

void solve(){
    string s;
    cin>>s;
    char c = s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!=c){
            cout<<"Yes";
            return ;
        }
    }
    cout<<"No";
    return ;

}

int main()
{
solve();
return 0;
    
}
/*const int maxSize = 1e5;
    long long n, a, b;
    cin >> n >> a >> b;
    long long multi = n/b;
    long long rem = n % b;
    if(multi > maxSize){
        cout << "NO\n";
        return 0;
    }
    vector<long long> ans(multi, b);
    if(rem != 0) {
        for(int i = 0; i < multi; i++) {
            long long d = max(0ll, min(a - rem, b - a));
            rem += d;
            ans[i] -= d;
        }
        if(rem < a) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout <<"YES\n";
    if(rem != 0)
        cout << rem << ' ';
    for(auto&v : ans)
        cout << v << ' ';*/

/**/
