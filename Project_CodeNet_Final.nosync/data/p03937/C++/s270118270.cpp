#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int h, w;
    string str;
    cin >> h >> w;

    vector<vector<string>> vec(h, vector<string>(w));

    for (int i = 0; i < h; i++) {
        cin >> str;
        for (int j = 0; j < w; j++) vec.at(i).at(j) = str.at(j);
    }

    for (int i = 0; i < h-1; i++) {
        for (int j = 1; j < w; j++) {
            if (vec.at(i).at(j) == ".") break;
            if(i > 0 && vec.at(i-1).at(j) == "#"){
                cout << "Impossible";
                return 0;
            }

            for (int k = 0; k < j; k++) {
                if (vec.at(i + 1).at(k) == "#") {
                    cout << "Impossible";
                    return 0;
                }
            }
            vec.at(i).at(j) = ".";
        }
    }

    if(vec.at(h-1).at(w-2) == "#" && vec.at(h-2).at(w-1) == "#"){
        cout << "Impossible";
        return 0;
    }
    
    cout << "Possible";
}