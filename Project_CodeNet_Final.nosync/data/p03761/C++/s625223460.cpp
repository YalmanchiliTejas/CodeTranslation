#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
	int n;
    cin >> n;
    string s[51];
    rep(i, n){
        cin >> s[i];
    }
    string ans;
    for(char c = 'a'; c <= 'z'; c++){
        int sml = 51;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < s[i].length(); j++){
                if(s[i][j] == c)
                    cnt++;
            }
            sml = min(sml, cnt);
        }
        for(int j = 0; j < sml; j++)
            ans += c;
    }
    cout << ans << endl;

    return 0;
}
