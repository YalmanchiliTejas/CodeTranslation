#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B;
    cin >> A >> B;
    vector<vector<int>> d(A+1, vector<int>(B+1));
    for(int i=1; i<=A; i++)
        for(int j=1; j<=B; j++)
            cin >> d[i][j];
    vector<vector<int>> f(101, vector<int>(101, 0));
    for(int a=0; a<=100; a++)
        for(int b=0; b<=100; b++)
            for(int x=1; x<=A; x++)
                for(int y=1; y<=B; y++)
                    f[a][b] = max(f[a][b], d[x][y]-a*x-b*y);

    for(int x=1; x<=A; x++)
        for(int y=1; y<=B; y++){
            int tmp = 1<<30;
            for(int a=0; a<=100; a++)
                for(int b=0; b<=100; b++)
                    tmp = min(tmp, f[a][b]+a*x+b*y);
            if(tmp != d[x][y]){
                cout << "Impossible" << endl;
                return 0;
            }
        }

    cout << "Possible" << endl;
    int N = 202;
    int M = 200 + 101*101;
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<100; i++)
        edges.push_back(make_tuple(i, i+1, -1));
    for(int i=101; i<201; i++)
        edges.push_back(make_tuple(i, i+1, -2));
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            edges.push_back(make_tuple(i, 201-j, f[i][j]));
    cout << N << " " << M << endl;
    for(auto e : edges){
        int u, v, c;
        tie(u, v, c) = e;
        cout << u+1 << " " << v+1 << " ";
        if(c == -1) cout << "X" << endl;
        else if(c == -2) cout << "Y" << endl;
        else cout << c << endl;
    }
    cout << 1 << " " << N << endl;
    return 0;
}