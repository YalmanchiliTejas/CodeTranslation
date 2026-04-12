#include<bits/stdc++.h>
using namespace std;

int main(){

    while(1){

        string s; cin >> s;
        if(s[0] == '#') break;

        //int a, b, c, d; cin >> a >> b >> c >> d;
        int w = 0;
        int h = 1;
        for(int i = 0; s[i] != '/'; i++){
            if(s[i] == 'b') w++;
            else w += (int)(s[i] - '0');
        }
        
        //cout << "ok" << endl;

        for(int i = 0; i != s.size(); i++){
            if(s[i] == '/') h++;
        }
        
        vector<vector<bool> > g(h, vector<bool> (w, false));

        int a, b, c, d; cin >> a >> b >> c >> d;
        int idx = 0;
        int i = 0, j = 0;
        while(idx != s.size()){
            //cout << i << " " << j << " " << idx << endl;
            if(s[idx] == '/'){
                i++;
                j = 0;
                idx++;
            }else if(s[idx] == 'b'){
                //cout << "ok" << endl;
                //cout << i << " "<< j << endl;
                g[i][j] = true;
                idx++;
                j++;
            }else{
                j += (int)(s[idx] - '0');
                idx++;
            }
        }

        /*for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }*/

        g[a - 1][b - 1] = false;
        g[c - 1][d - 1] = true;
        for(int i = 0; i < h; i++){
            int num = 0;
            for(int j = 0; j < w; j++){
                if(g[i][j]){
                    if(num > 0) cout << num << 'b';
                    else cout << 'b';
                    num = 0;
                }else num++;

                if(j == w - 1){
                    if(num > 0) cout << num;
                }
            }
            if(i != h - 1) cout << '/';
        }

        cout << endl;
    }

    return 0;
}
