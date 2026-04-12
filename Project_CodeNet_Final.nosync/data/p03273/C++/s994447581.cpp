#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<string> A(H);
    for(string &s:A) cin >> s;

    vector<int> d_row;
    vector<int> d_col;

    for(int i=0; i<H; i++){
        int cr = 0;
        for(int j=0; j<W; j++) if(A[i][j]=='.') cr++;
        if(cr==W) d_row.push_back(i);
    }

    for(int i=0; i<W; i++){
        int cc = 0;
        for(int j=0; j<H; j++) if(A[j][i]=='.') cc++;
        if(cc==H) d_col.push_back(i);
    }

    for(int i=0; i<H; i++){
        if(find(d_row.begin(), d_row.end(), i)!=d_row.end()) continue;
        for(int j=0; j<W; j++){
            if(find(d_col.begin(), d_col.end(), j)!=d_col.end()) continue;
            cout << A[i][j];
        }
        cout << endl;
    }
    
    

    return 0;
}
