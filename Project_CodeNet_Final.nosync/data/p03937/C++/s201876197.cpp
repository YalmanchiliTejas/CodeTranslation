#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    int h,w,cnt = 0;
    cin >> h >> w;
    for(int i = 0;i < h;i++){
        string s;
        cin >> s;
        for(auto c:s) if(c == '#') cnt++;
    }
    if(cnt == w+h-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
