    /**
     *      ABC 64 A
     *      author  : kyomukyomupurin
     *      created : 2018-09-04 23:44:14
    **/
     
    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int r, g, b; cin >> r >> g >> b;
        (g * 10 + b) % 4 == 0 ? cout << "YES" : cout << "NO";
     
        return 0;
    }