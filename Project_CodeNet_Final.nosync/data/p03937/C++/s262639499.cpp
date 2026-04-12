#include <iostream>
using namespace std;
int main() {
    int h, w, cnt=0;
    cin >> h >> w;
    string s;
    for(int i=0; i<h; i++) {
        cin >> s;
        for(int j=0; j<w; j++) if(s[j]=='#') cnt++;
    }
    if(cnt==h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
