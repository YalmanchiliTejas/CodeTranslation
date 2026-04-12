#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for(int i=0; i<h; i++){
        cin >> a[i];
    }

    for(int bit=0; bit<(1<<(h+w-2)); bit++){
        if(__builtin_popcount(bit) != h-1) continue;
        //bitset<16> b(bit);
        //cout << b << endl;

        vector<string> test(h, "");
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                test[i] += '.';
            }
        }

        int x = 0;
        int y = 0;
        test[0][0] = '#';

        for(int i=0; i<(h+w); i++){
            if(bit >> i & 1) x += 1;
            else y += 1;

            //cout << x << " " << y << endl;
            test[x][y] = '#';
        }

        bool flag = true;
        for(int i=0; i<h; i++){
            if(a[i] != test[i]) flag = false;
        }
        if(flag == true){
            cout << "Possible" << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}