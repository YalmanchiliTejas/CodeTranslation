#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int h, w;
    cin >> h >> w;
    char a[h+1][w+1];
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> a[i][j];
        }
    }

    set<int> kara;
    for(int i=1; i<=h; i++){
        int cnt = 0;
        for(int j=1; j<=w; j++){
            if(a[i][j] == '.') cnt++;
        }
        if(cnt == w){
            for(int j=1; j<=w; j++){
                a[i][j] = '!';
                kara.insert(i);
            }
        }
    }


    for(int j=1; j<=w; j++){
        int cnt = 0;
        for(int i=1; i<=h; i++){
            if(a[i][j] == '.' || a[i][j] == '!'){
                cnt++;
            }
        }
        if(cnt == h){
            for(int i=1; i<=h; i++){
                a[i][j] = '!';
            }
        }
    }


    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(a[i][j] != '!'){
                cout << a[i][j];
            }
        }
        if(kara.find(i) == kara.end()){
            cout << endl;
        }
    }
    return 0;
}