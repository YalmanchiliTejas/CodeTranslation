#include <iostream>
#include <string>
#include <vector>

#define cal(i, n) for(int i = 0 ; i < n ; i++)
#define els(i, p) for(int i = int(p) - 1 ; i >= 0 ; i--)

using namespace std;

int main(){
    int H, W;
    vector<string> a(100);
    vector<int> ev;
    vector<int> eh;
    cin >> H >> W;
    cal(i, H) cin >> a[i];
    cal(i, H) {
        int total = 0;
        cal(j, W) total += a[i][j];
        if (total == 46 * W){
            ev.push_back(i);
        }
    }
    cal(i, W){
        int total = 0;
        cal(j, H) total += a[j][i];
        if (total == 46 * H){
            eh.push_back(i);
        }
    }
    els(i, ev.size()){
        a.erase(a.begin() + ev[i]);
    }
    els(i, eh.size()){
        cal(j, H - ev.size()){
            a[j].erase(eh[i],1);
        }
    }
    cal(i, a.size()){
        cout << a[i] << endl;
    }
    
    return 0;

}
