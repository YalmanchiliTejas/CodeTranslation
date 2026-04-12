#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
const int INF = 100000000;
using namespace std;

const int kN = 100;

struct P{
    int x, y;
};

void swap(char m[kN][kN], P b, P a){
    char temp = m[b.x][b.y];
    m[b.x][b.y] = m[a.x][a.y];
    m[a.x][a.y] = temp;
}

int main(){
    string s;
    while(cin >> s, s[0] != '#'){
        char m[kN][kN];
        rep(i,kN) rep(j,kN) m[i][j] = '\0';

        P b, a;
        cin >> b.x >> b.y >> a.x >> a.y;
        b.x--; b.y--; a.x--; a.y--;

        vector<string> v;
        string temp;

        s+='/';
        rep(i,s.size()){
            if(s[i] == '/'){
                v.emplace_back(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }

        rep(i,v.size()){
            int p = 0;
            rep(j,v[i].size()){
                if(v[i][j] == 'b'){
                    m[i][p] = 'b';
                    p++;
                }
                else{
                    for(int k = 0; k < v[i][j] - '0'; k++){
                        m[i][p] = '.';
                        p++;
                    }
                }
            }
        }
        /*
        for(int i = 0; m[i][0] != '\0'; i++){
            for(int j = 0; m[i][j] != '\0'; j++){
                cout << m[i][j];
            }
            cout << endl;
        }
        */
        swap(m, b, a);
        /*
        for(int i = 0; m[i][0] != '\0'; i++){
            for(int j = 0; m[i][j] != '\0'; j++){
                cout << m[i][j];
            }
            cout << endl;
        }
        */

        for(int i = 0; m[i][0] != '\0'; i++){
            if(i) cout << '/';
            int cnt = 0;
            for(int j = 0; m[i][j] != '\0'; j++){
                if(m[i][j] =='b'){
                    if(cnt) cout << cnt;
                    cnt = 0;
                    cout << 'b';
                }else if(m[i][j] == '.'){
                    cnt++;
                }
            }
            if(cnt) cout << cnt;
        }
        cout << endl;
    }
}