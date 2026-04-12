#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int n;
    cin >> n;
    int count[26][50] = {0};
    rep(i, n){
        string s;
        cin >> s;
        rep(j, s.size())count[s[j]-'a'][i]++;
    }
    rep(i, 26)sort(count[i], count[i]+n);

    string ans = "";
    rep(i, 26){
        rep(j, count[i][0])ans += 'a'+i;
    }
    cout << ans << endl;
}