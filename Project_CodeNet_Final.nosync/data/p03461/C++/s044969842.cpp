#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 101;
const int mod = 1e9 + 7;

using namespace std;

int A, B;
int d[N][N];
int ga[N][N];
int gb[N][N];
int gc[N][N];
bool us[N][N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> A >> B;
        for(int i = 1; i <= A; i++){
                for(int j = 1; j <= B; j++){
                        cin >> d[i][j];
                        ga[i][j] = -1;
                }
        }
        vector < int > a, b, c;
        for(int x = 0; x <= 100; x++){
                for(int y = 0; y <= 100; y++){
                        for(int z = 0; z <= 100; z++){
                                bool good = true;
                                for(int i = 1; i <= A && good; i++){
                                        for(int j = 1; j <= B; j++){
                                                if(i * x + j * y + z < d[i][j]){
                                                        good = false;
                                                        break;
                                                }
                                        }
                                }
                                if(good){
                                        for(int i = 1; i <= A; i++){
                                                for(int j = 1; j <= B; j++){
                                                        if(i * x + j * y + z == d[i][j]){
                                                                if(ga[i][j] == -1 || x + y < ga[i][j] + gb[i][j]){
                                                                        ga[i][j] = x;
                                                                        gb[i][j] = y;
                                                                        gc[i][j] = z;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
        int res = 1;
        for(int i = 1; i <= A; i++){
                for(int j = 1; j <= B; j++){
                        if(ga[i][j] == -1){
                                cout << "Impossible" << "\n";
                                return 0;
                        }
                        int x = ga[i][j], y = gb[i][j], z = gc[i][j];
                        if(!us[x][y][z]){
                                us[x][y][z] = 1;
                                a.push_back(x);
                                b.push_back(y);
                                c.push_back(z);
                        }
                }
        }

        int G = 2;
        vector < pair < pair < int, int >, int > > E;
        for(int i = 0; i < a.size(); i++){
                int s = 1;
                for(int j = 0; j < a[i]; j++){
                        G += 1;
                        E.push_back({{s, G}, -1});
                        s = G;
                }
                for(int j = 0; j < b[i]; j++){
                        G += 1;
                        E.push_back({{s, G}, -2});
                        s = G;
                }
                E.push_back({{s, 2}, c[i]});
        }
        assert(G <= 300);
        cout << "Possible" << "\n";
        cout << G << " " << E.size() << "\n";
        for(auto p: E){
                cout << p.fi.fi << ' ' << p.fi.se << ' ';
                if(p.se == -1){
                        cout << "X\n";
                } else if(p.se == -2){
                        cout << "Y\n";
                } else{
                        cout << p.se << "\n";
                }
        }
        cout << "1 2\n";
}
