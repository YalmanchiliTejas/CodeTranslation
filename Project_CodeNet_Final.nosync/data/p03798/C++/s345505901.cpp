#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

string d[4] = {"SS", "SW", "WS", "WW"};

signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    REP(i,4){
        string ans = d[i];
        for(int i = 1; i < n - 1; i++){
            if(s[i] == 'o'){
                if(ans[i] == 'S'){
                    ans.push_back(ans[i - 1]);
                }else{
                    if(ans[i - 1] == 'S'){
                        ans.push_back('W');
                    }else{
                        ans.push_back('S');
                    }
                }
            }else{
                if(ans[i] == 'S'){
                    if(ans[i - 1] == 'S'){
                        ans.push_back('W');
                    }else{
                        ans.push_back('S');
                    }
                }else{
                    ans.push_back(ans[i - 1]);
                }
            }
        }
        bool isok = true;
        if(s[n - 1] == 'o'){
            if(ans[n - 1] == 'S'){
                if(ans[0] != ans[n - 2]){
                    isok = false;
                }
            }else{
                if(ans[0] == ans[n - 2]){
                    isok = false;
                }
            }
        }else{
            if(ans[n - 1] == 'S'){
                if(ans[0] == ans[n - 2]){
                    isok = false;
                }
            }else{
                if(ans[0] != ans[n - 2]){
                    isok = false;
                }
            }
        }
        if(s[0] == 'o'){
            if(ans[0] == 'S'){
                if(ans[1] != ans[n - 1]){
                    isok = false;
                }
            }else{
                if(ans[1] == ans[n - 1]){
                    isok = false;
                }
            }
        }else{
            if(ans[0] == 'S'){
                if(ans[1] == ans[n - 1]){
                    isok = false;
                }
            }else{
                if(ans[1] != ans[n - 1]){
                    isok = false;
                }
            }
        }
        if(isok == true){
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}