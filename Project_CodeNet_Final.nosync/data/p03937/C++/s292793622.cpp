#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> A(H+2, vector<char>(W+2, '.'));
    for(int i=1; i<H+1; i++){
        for(int j=1; j<W+1; j++){
            cin >> A.at(i).at(j);
        }
    }
    vector<vector<int>> used(H+2, vector<int>(W+2, -1));

    queue<int> quex;
    queue<int> quey;
    quex.push(1);
    quey.push(1);
    used.at(1).at(1) = 0;

    while(!quex.empty() && !quey.empty()){        
        int x = quex.front();
        int y = quey.front();
        quex.pop();
        quey.pop();

        if(A.at(y).at(x+1) == '#' && A.at(y+1).at(x) == '#'){
            cout << "Impossible" << endl;
            return 0;
        }

        if(A.at(y).at(x-1) == '#' && used.at(y).at(x-1) == -1){
            break;
        }

        if(A.at(y-1).at(x) == '#' && used.at(y-1).at(x) == -1){
            //cout << x << y << endl; 
            break;
        }        

        if(A.at(y).at(x+1) == '#' && used.at(y).at(x+1) == -1){
            quex.push(x+1);
            quey.push(y);
            used.at(y).at(x+1) = used.at(y).at(x) + 1;
        }
        else if(A.at(y+1).at(x) == '#' && used.at(y+1).at(x) == -1){
            quex.push(x);
            quey.push(y+1);
            used.at(y+1).at(x) = used.at(y).at(x) + 1;
        }

        if(x == W && y == H && quex.empty() && quey.empty()){
            cout << "Possible" << endl;
            return 0;
        }

    }

    cout << "Impossible" << endl;

}
