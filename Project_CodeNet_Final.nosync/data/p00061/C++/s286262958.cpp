#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int main() {

    vector<int> pts(100);
    int id, pt;
    char comma;
    while(cin >> id >> comma >> pt && (id || pt)) {
        pts[id] = pt; 
    }

    vector<int> upts;
    for (int i = 30; i >= 0; i--) {
        if(find(pts.begin(), pts.end(), i) != pts.end()) {
            upts.push_back(i);
        }
    }

    while(cin >> id) {

        int res = 1;
        for(int i = 0; i <= 30; i++) {
            if(pts[id] != upts[i]) {
                res += 1;
            } else {
                break;
            }
        }
        cout << res << endl;
    }
     
    return 0;
}