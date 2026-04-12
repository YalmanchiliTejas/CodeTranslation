#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int cnt[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string S;
    int K;
    cin >> S >> K;
    ll ans = 0;
    int N = S.size();
    cnt[0] = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] != '0'){
            cnt[i+1] = cnt[i]+1;
        }else{
            cnt[i+1] = cnt[i];
        }
    }
    if(K == 1){
        for(int i = 0; i < S.size(); i++){
            int c = S[i]-'0';
            if(i == 0){
                ans += c;
            }else{
                ans += 9;
            }
        }
    }
    if(K == 2){
        for(int i = 0; i < S.size(); i++){
            for(int j = i+1; j < S.size(); j++){
                int c = S[i]-'0';
                int d = S[j]-'0';
                if(cnt[i] == 0){
                    if(cnt[j] == 1){
                        if(c != 0) ans += 9*(c-1)+d;
                    }else{
                        ans += 9*c;
                    }
                }else{
                    ans += 9*9;
                }
            }
        }
    }
    if(K == 3){
        for(int i = 0; i < S.size(); i++){
            for(int j = i+1; j < S.size(); j++){
                for(int k = j+1; k < S.size(); k++){
                    int c = S[i]-'0';
                    int d = S[j]-'0';
                    int e = S[k]-'0';
                    if(cnt[i] == 0){
                        if(cnt[j] == 1){
                            if(cnt[k] == 2){
                                ans += (e);
                                if(d != 0) ans += 9*(d-1);
                                if(c != 0) ans += (c-1)*9*9;
                            }else{
                                ans += 9*(d);
                                if(c != 0) ans += (c-1)*9*9;
                            }
                        }else{
                            ans += c*9*9;
                        }
                    }else{
                        ans += 9*9*9;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}