#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    ll minl = 1e9, minIndex = 0;
    vector<string> s(n); rep(i,n){
        cin >> s[i];
        if(minl >= s[i].size()){
            sort(s[i].begin(), s[i].end());
            if(s[i] < s[minIndex] and minl == s[i].size()){
                minIndex = i;
            }else{
                minl = s[i].size();
                minIndex = i;
            }
        }
    }

    vector<char> ans;

    for(auto x:s[minIndex]){
        ll flag = 1;
        for(int j = 0; j < n; j++){
            ll index = s[j].find(x);
            if(string::npos == index){
                flag = 0;
                break;
            }else if(j != minIndex){
                s[j][index] = '#';
            }
        }
        if(flag) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for(auto x:ans) cout << x; cout << endl;
}