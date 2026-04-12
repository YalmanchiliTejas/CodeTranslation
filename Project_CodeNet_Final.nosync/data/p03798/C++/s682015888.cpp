#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    for (int i1 = 0; i1 < 2; i1++){
        for (int i2 = 0; i2 < 2; i2++){
            a[0] = i1;
            a[1] = i2;
            for (int i = 1; i < n - 1; i++){
                if((s[i] == 'o' && a[i] == 0) || (s[i] == 'x' && a[i] == 1)) a[i+1] = a[i-1];
                else a[i+1] = a[i-1] ^ 1;
            }
            // 結果に矛盾がないことのフラグ
            bool flag = false;
            if((s[n-1] == 'o' && a[n-1] == 0 && a[n-2] == a[0]) || (s[n-1] == 'x' && a[n-1] == 1 && a[n-2] == a[0])){
                if((s[0] == 'o' && a[0] == 0 && a[n-1] == a[1]) || (s[0] == 'x' && a[0] == 1 && a[n-1] == a[1])){
                    flag = true;
                }else if((s[0] == 'x' && a[0] == 0 && a[n-1] != a[1]) || (s[0] == 'o' && a[0] == 1 && a[n-1] != a[1])){
                    flag = true;
                }
            }else if((s[n-1] == 'x' && a[n-1] == 0 && a[n-2] != a[0]) || (s[n-1] == 'o' && a[n-1] == 1 && a[n-2] != a[0])){
                if((s[0] == 'o' && a[0] == 0 && a[n-1] == a[1]) || (s[0] == 'x' && a[0] == 1 && a[n-1] == a[1])){
                    flag = true;
                }else if((s[0] == 'x' && a[0] == 0 && a[n-1] != a[1]) || (s[0] == 'o' && a[0] == 1 && a[n-1] != a[1])){
                    flag = true;
                }
            }

            if(flag){
                rep(i, n){
                    if (a[i] == 0) cout << 'S';
                    else cout << 'W';
                }cout << endl;
                return 0;
            }

            // rep(i, n) cout << a[i] << " ";
            // cout << endl;
        }
    }
    cout << -1 << endl;
}
