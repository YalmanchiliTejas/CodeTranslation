#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)
 
 
int main()
{
    int h,w;cin>>h>>w;
    int b = 0;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            cin>>a[i][j];
            if(a[i][j] == '#') b++;
        }    
    }
    cout << (b == h + w - 1 ? "Possible":"Impossible") << endl;
    return 0;
    
}
