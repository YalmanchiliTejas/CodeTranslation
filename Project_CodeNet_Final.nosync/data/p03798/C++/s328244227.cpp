#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<string> two = {"SS", "SW", "WS", "WW"};
    string ans = "";
    rep(i,4){
        string tmp = two[i];
        bool isOK = false;
        for(int i = 1; i < n; ++i){
            if(s[i]=='o'){
                if(tmp[i]=='S') tmp += (tmp[i-1] == 'S' ? 'S' : 'W');
                else tmp += (tmp[i-1] == 'S' ? 'W' : 'S');
            }else{
                if(tmp[i]=='S') tmp += (tmp[i-1] == 'S' ? 'W' : 'S');
                else tmp += (tmp[i-1] == 'S' ? 'S' : 'W');
            }
        }
        if(tmp[n] == tmp[0]){
            if(s[0] == 'o'){
                if(tmp[0]=='S' && tmp[n-1] == tmp[1]) isOK = true;
                else if (tmp[0]=='W' && tmp[n-1] != tmp[1]) isOK = true;
            }else{
                if(tmp[0]=='S' && tmp[n-1] != tmp[1]) isOK = true;
                else if (tmp[0]=='W' && tmp[n-1] == tmp[1]) isOK = true;
            }
        }
        /*
        if(s[0] == 'o'){
            if(tmp[0]=='S' && tmp[n-1] == tmp[1]) isOK = true;
            else if (tmp[0]=='W' && tmp[n-1] != tmp[1]) isOK = true;
        }else{
            if(tmp[0]=='S' && tmp[n-1] != tmp[1]) isOK = true;
            else if (tmp[0]=='W' && tmp[n-1] == tmp[1]) isOK = true;
        }
        */
        if(isOK) {
            tmp.pop_back();
            ans = tmp;
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}