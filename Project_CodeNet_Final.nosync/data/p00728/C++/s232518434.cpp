#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        int n;
        while(cin >> n, n) {
                vector<int> score;
                for(int i=0; i<n; i++) {
                        int k;
                        cin >> k;
                        score.push_back(k);
                }
                sort( score.begin(), score.end() );
                int res = 0;
                for(int i=1; i<n-1; i++) {
                        res += score[i];
                }
                cout << res/(n-2) << endl;
        }
        return 0;
}