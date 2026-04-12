#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define INF 1000000
using namespace std;
int main(){
    string s;
    while(cin >> s){
        if(s == "#") break;
        char table[10][10];
        int posy = 0,posx = 0;
        rep(i,s.size()){
            if(s[i] == 'b') {
                table[posy][posx] = 'b';
                posx++;
            }
            else if(s[i] == '/') {
                posy++;
                posx = 0;
            }
            else {
                int tmp = s[i]-'0';
                for(int j=0; j<tmp; j++) {
                    table[posy][posx] = '.';
                    posx++;
                }
            }
        }
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--; posy++;
        swap(table[a][b],table[c][d]);
        vector<char> vec;
        rep(i,posy){
            int cnt = 0;
            bool flag = false;
            rep(j,posx){
                if(table[i][j] == 'b') {
                    if(flag == true) {
                        vec.push_back(cnt+'0');
                        cnt = 0;
                    }
                    vec.push_back('b');
                    flag = false;
                }
                else {
                    cnt++;
                    flag = true;
                }
            }
            if(flag == true) {
                vec.push_back(cnt+'0');
                flag = false;
            }
            if(i != posy-1) vec.push_back('/');
        }
        rep(i,vec.size()) cout << vec[i];
        cout << endl;
    }
    return 0;
}
