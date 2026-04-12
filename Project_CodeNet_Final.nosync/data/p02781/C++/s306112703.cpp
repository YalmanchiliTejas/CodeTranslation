#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    string n;
    string n2 = "";
    string n3 = "";
    ll k;
    cin >> n >> k;

    ll ans = 0;
    ll len = n.size();

    if(k == 1){
        ans = (len - 1) * 9 + ll(char(n[0])) - ll(char('0'));
    }else if(k == 2){
        ans = (len - 1) * (len - 2) / 2 * 9 * 9;
        ans += (ll(char(n[0])) - ll(char('0')) - 1) * 9 * (len - 1);

        bool flag = false;
        rep(i, 1, len){
            if(n[i] != '0'){
                flag = true;
            }
            if(flag){
                n2 += n[i];
            }
        }

        ll len2 = n2.size();
        if(len2 <= 0){
            cout << ans << endl;
            return 0;
        }
        ans += (len2 - 1) * 9 + ll(char(n2[0])) - ll(char('0'));
    }else if(k == 3){
        ans = (len - 1) * (len - 2) * (len - 3) / 6 * 9 * 9 * 9;
        ans += (ll(char(n[0])) - ll(char('0')) - 1) * (len - 1) * (len - 2) / 2 * 9 * 9;

        bool flag = false;
        rep(i, 1, len){
            if(n[i] != '0'){
                flag = true;
            }
            if(flag){
                n2 += n[i];
            }
        }

        ll len2 = n2.size();
        if(len2 <= 1){
            cout << ans << endl;
            return 0;
        }
        ans += (len2 - 1) * (len2 - 2) / 2 * 9 * 9;
        ans += (ll(char(n2[0])) - ll(char('0')) - 1) * 9 * (len2 - 1);

        flag = false;
        rep(i, 1, len2){
            if(n2[i] != '0'){
                flag = true;
            }
            if(flag){
                n3 += n2[i];
            }
        }

        ll len3 = n3.size();
        if(len3 <= 0){
            cout << ans << endl;
            return 0;
        }
        ans += (len3 - 1) * 9 + ll(char(n3[0])) - ll(char('0'));
    }

    cout << ans << endl;
}
