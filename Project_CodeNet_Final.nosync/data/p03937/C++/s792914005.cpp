#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
int H, W;
cin >> H >> W;

vector<string> A(H);
for( int i = 0; i < H; i++ ) cin >> A.at(i);

int fg = 0;
for( int i = 0; i < H; i++ ){
for( int j = 0; j < W; j++ ){
if( j < fg && A.at(i).at(j) == '#' ){
cout << "Impossible" << endl;
return 0;
}else if( A.at(i).at(j) == '#' ) fg = j;
}
}
cout << "Possible" << endl;

}
