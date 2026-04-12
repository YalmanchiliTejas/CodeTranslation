#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    ll n;cin>>n;
    vector<int> alphabet(26,0);
    vector<string> s(n);
    For(i,0,n) cin >> s[i];
    For(j,0,s[0].size()) alphabet[s[0][j]-'a'] ++;
    For(i,0,n){
        vector<int> alphabeti(26,0);
        For(j,0,s[i].size()) alphabeti[s[i][j]-'a'] ++;
        For(j,0,26) alphabet[j] = min(alphabet[j],alphabeti[j]);
    }
    string t="";
    For(i,0,26){
        For(j,0,alphabet[i]) t.push_back(i+'a');
    }
    cout << t << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}