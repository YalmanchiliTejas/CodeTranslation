#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int H,W; cin>> H>>W;
    int count =0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char c; cin >> c;
            if(c=='#') count++;
        }
    }
    if(count == H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
