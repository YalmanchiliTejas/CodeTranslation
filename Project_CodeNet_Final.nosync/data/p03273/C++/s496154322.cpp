#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    for(int i = 0; i < h; i++) cin >> a[i];

    for(int i = 0; i < h;){
        int cnt = 0;
        for(int j = 0; j < w; j++) if(a[i][j] == '.') cnt++;
        if(cnt == w){
            a.erase(a.begin()+i);
            h--;
        }else i++;
    }
    for(int i = 0; i < w;){
        int cnt = 0;
        for(int j = 0; j < h; j++) if(a[j][i] == '.') cnt++;
        if(cnt == h){
            for(int k = 0; k < h; k++) a[k].erase(a[k].begin()+i);
            w--;
        }else i++;
    }

    for(auto i : a) cout << i << endl;

    return 0;
}