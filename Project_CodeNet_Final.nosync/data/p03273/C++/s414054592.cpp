#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int w , h;
    cin >> h >> w;

    vector<string> s;
    s.resize(h);

    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    vector<bool> fh(h), fw(w);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if ( s[i][j] == '#' ) {
                fh[i] = true;
                fw[j] = true;
            }
        }
        
    }
    
    
    for (int i = 0; i < h; i++) {
        int c = 0;
        for (int j = 0; j < w; j++){
            if (fw[j]&&fh[i]) {
                cout << s[i][j];
                c++;
            }
        }
        if (c >0 ) cout << endl;
    }    
    return 0;
}